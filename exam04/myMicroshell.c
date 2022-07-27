#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#define SIDE_OUT 0
#define SIDE_IN 1

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define TYPE_END 0
#define TYPE_PIPE 1
#define TYPE_BREAK 2

typedef struct s_list {
	char	**args;
	int		len;
	int		type;
	int		pipe[2];
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int ft_strlen(char *str) {
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void show_error(char *str) {
	write(STDERR, str, ft_strlen(str));
}

void exit_fatal() {
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
}

char *ft_strdup(char *str) {
	char *tmp;
	int i;

	if (!(tmp = (char*)malloc(ft_strlen(str) +  1)))
		exit_fatal();
	i = 0;
	while (str[i]) {
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

void add_arg(t_list *cmd, char *arg) {
	char **tmp;
	int i;

	i = 0;
	tmp = 0;
	if (!(tmp = (char**)malloc(sizeof(char*) * (cmd->len + 2))))
		exit_fatal();
	while (i < cmd->len) {
		tmp[i] = cmd->args[i];
		i++;
	}
	if (cmd->len > 0)
		free(cmd->args);
	cmd->args = tmp;
	cmd->args[i++] = ft_strdup(arg);
	cmd->args[i] = 0;
	cmd->len++;
}

void list_push(t_list **list, char *arg) {
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		exit_fatal();
	new->args = 0;
	new->len = 0;
	new->type = TYPE_END;
	new->prev = 0;
	new->next = 0;
	if (*list) {
		(*list)->next = new;
		new->prev = *list;
	}
	*list = new;
	add_arg(new, arg);
}

void parse_arg(t_list **cmds, char *arg) {
	int is_break;

	if (strcmp(";", arg) == 0)
		is_break = 1;
	else
		is_break = 0;
	if (is_break && !*cmds)
		return ;
	else if (!is_break && (!*cmds || (*cmds)->type > TYPE_END))
		list_push(cmds, arg);
	else if (strcmp("|", arg) == 0)
		(*cmds)->type = TYPE_PIPE;
	else if (is_break)
		(*cmds)->type = TYPE_BREAK;
	else
		add_arg(*cmds, arg);
}

void list_rewind(t_list **cmds) {
	while (*cmds && (*cmds)->prev)
		*cmds = (*cmds)->prev;
}

void list_clear(t_list **cmds) {
	t_list *tmp;
	int i;

	list_rewind(cmds);
	while(*cmds) {
		tmp = (*cmds)->next;
		i = 0;
		while (i < (*cmds)->len)
			free((*cmds)->args[i++]);
		free((*cmds)->args);
		free(*cmds);
		*cmds = tmp;
	}
	*cmds = 0;
}

int exec_cmd(t_list *cmd, char **env) {
	pid_t pid;
	int ret;
	int status;
	int pipe_open;

	ret = EXIT_FAILURE;
	pipe_open = 0;
	if (cmd->type == TYPE_PIPE || (cmd->prev && cmd->prev->type == TYPE_PIPE)) {
		pipe_open = 1;
		if (pipe(cmd->pipe))
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0) {
		if (cmd->type == TYPE_PIPE
			&& dup2(cmd->pipe[SIDE_IN], STDOUT) < 0)
			exit_fatal();
		if (cmd->prev && cmd->prev->type == TYPE_PIPE && dup2(cmd->prev->pipe[SIDE_OUT], STDIN) < 0)
			exit_fatal();
		if ((ret = execve(cmd->args[0], cmd->args, env)) < 0) {
			show_error("error: cannot execute ");
			show_error(cmd->args[0]);
			show_error("\n");
		}
		exit(ret);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(cmd->pipe[SIDE_IN]);
			if (!cmd->next || cmd->type == TYPE_BREAK)
				close(cmd->pipe[SIDE_OUT]);
		}
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			close(cmd->prev->pipe[SIDE_OUT]);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}

int exec_cmds(t_list **cmds, char **env) {
	t_list *tmp;
	int ret;

	ret = EXIT_SUCCESS;
	list_rewind(cmds);
	while (*cmds) {
		tmp = *cmds;
		if (strcmp("cd", tmp->args[0]) == 0) {
			ret = EXIT_SUCCESS;
			if (tmp->len < 2) {
				ret = EXIT_FAILURE;
				show_error("error: cd: bad arguments\n");
			}
			else if (chdir(tmp->args[1])) {
				ret = EXIT_FAILURE;
				show_error("error: cd: cannot change directory to ");
				show_error(tmp->args[1]);
				show_error("\n");
			}
		}
		else
			ret = exec_cmd(tmp, env);
		if (!(*cmds)->next)
			break;
		*cmds = (*cmds)->next;
	}
	return ret;
}

int main(int argc, char **argv, char **env) {
	t_list *cmds;
	int i;
	int ret;

	ret = EXIT_SUCCESS;
	cmds = 0;
	i = 1;
	while (i < argc)
		parse_arg(&cmds, argv[i++]);
	if (cmds)
		ret = exec_cmds(&cmds, env);
	list_clear(&cmds);
	return (ret);
}
