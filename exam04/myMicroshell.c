#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define SIDE_OUT 0
#define SIDE_IN 1

#define STD_IN 0
#define STD_OUT 1
#define STD_ERR 2

#define TYPE_END 0
#define TYPE_PIPE 1
#define TYPE_BREAK 2

typedef struct s_list {
	char **args;
	int length;
	int type;
	int pipes[2];
	struct s_list *prev;
	struct s_list *next;
} t_list;

int ft_strlen(char *str) {
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}

int show_error(char *str) {
	if (str)
		write(STD_ERR, str, ft_strlen(str));
	return (1);
}

int exit_fatal(void) {
	show_error("error: fatal\n");
	exit(1);
	return 1;
}

void *exit_fatal_ptr(void) {
	exit_fatal();
	exit(1);
	return 0;
}

char *ft_strdup(char *str) {
	char *tmp;
	int i;

	tmp = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!tmp)
		return (exit_fatal_ptr());
	i = 0;
	while (str[i]) {
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return tmp;
}

int add_arg(t_list *cmd, char *arg) {
	char **tmp;
	int i;

	i = 0;
	tmp = (char**)malloc(sizeof(char*) * (cmd->length + 2));
	if (!tmp)
		return exit_fatal();
	while (i < cmd->length) {
		tmp[i] = cmd->args[i];
		i++;
	}
	tmp[i++] = ft_strdup(arg);
	tmp[i] = 0;
	if (cmd->args)
		free(cmd->args);
	cmd->args = tmp;
	cmd->length++;
	return 0;
}

int list_push(t_list **list, char *arg) {
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return exit_fatal();
	new->args = 0;
	new->length = 0;
	new->type = TYPE_END;
	new->prev = 0;
	new->next = 0;
	if (*list) {
		(*list)->next = new;
		new->prev = *list;
	}
	*list = new;
	return add_arg(*list, arg);
}

int list_rewind(t_list **list) {
	while(*list && (*list)->prev)
		*list = (*list)->prev;
	return 0;
}

int parse_arg(t_list **cmds, char *arg) {
	int is_break;

	is_break = (strcmp(";", arg) == 0);
	if (is_break && !*cmds)	// 끝
		return 0;
	else if (!is_break && (!*cmds || (*cmds)->type > TYPE_END)) // 처음이거나, 전 명령어가 파이프거나, 브레이크여서 새 명령어 추가하는 경우 새 리스트 추가
		return list_push(cmds, arg);
	else if (strcmp("|", arg) == 0) // 만약 파이프다
		(*cmds)->type = TYPE_PIPE;
	else if (is_break)	// 만약 브레이크다
		(*cmds)->type = TYPE_BREAK;
	else	// 그냥 기존 명령어의 옵션이거나 인자일 경우
		return add_arg(*cmds, arg);
	return 0;
}

int exec_cmd(t_list *cmd, char **env) {
	pid_t pid;
	int ret = 0;
	int status;
	int pipe_open;

	ret = 1;
	pipe_open = 0;
	if (cmd->type == TYPE_PIPE || (cmd->prev && cmd->prev->type == TYPE_PIPE)) {
		pipe_open = 1;
		if (pipe(cmd->pipes))
			return exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		return exit_fatal();
	else if (pid == 0) {
		if (cmd->type == TYPE_PIPE && dup2(cmd->pipes[SIDE_IN], STD_OUT) < 0)
			return exit_fatal();
		if (cmd->prev->type == TYPE_PIPE && dup2(cmd->prev->pipes[SIDE_OUT], STD_IN) < 0)
			return exit_fatal();
		if ((ret = execve(cmd->args[0], cmd->args, env)) < 0) {
			show_error("error: cannot execute ");
			show_error(cmd->args[0]);
			show_error("\n");
		}
		exit(ret);
	}
	else {
		waitpid(pid, &status, 0);
		if (pipe_open) {
			close(cmd->pipes[SIDE_IN]);
			if (!cmd->next || cmd->type == TYPE_BREAK)
				close(cmd->pipes[SIDE_OUT]);
		}
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			close(cmd->prev->pipes[SIDE_OUT]);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return ret;
}

int exec_cmds(t_list **cmds, char **env) {
	t_list *parser;
	int ret = 0;
	list_rewind(cmds);
	while (*cmds) {
		parser = *cmds;
		if (strcmp("cd", parser->args[0]) == 0) { // 빌트인 cd
			ret = 0;
			if (parser->length < 2)
				ret = show_error("error: cd: bad arguments\n");
			else if (chdir(parser->args[1])) {
				ret = show_error("error: cd: cannot change directory to ");
				show_error(parser->args[1]);
				show_error("\n");
			}
		}
		else {
			ret = exec_cmd(parser, env);
		}
		if (!(*cmds)->next) // rewind를 위해서 마지막까지 안감
			break;
		*cmds = (*cmds)->next;
	}
	return ret;
}

int main(int argc, char **argv, char**env) {
	t_list *cmds = 0;
	int i = 1;
	int ret = 0;

	while (i < argc)
		parse_arg(&cmds, argv[i++]);
	if (cmds)
		ret = exec_cmds(&cmds, env);
	return ret;
}
