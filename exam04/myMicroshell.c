#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define SIDE_OUT	0
#define SIDE_IN		1

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	0
#define TYPE_PIPE	1
#define TYPE_BREAK	2

typedef struct s_list
{
	char			**args;
	int				length;
	int				type;
	int				pipe[2];
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int ft_strlen(char *str) {
	int i;

	i = 0;
	while (str[i])
		++i;
	return i;
}

int show_error(char *str) {
	if (str)
		write(STDERR, str, ft_strlen(str));
	return EXIT_FAILURE;
}

int exit_fatal(void) {
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
	return EXIT_FAILURE;
}

void *exit_fatal_ptr(void) {
	exit_fatal();
	exit(EXIT_FAILURE);
	return 0;
}

char *ft_strdup(char *str) {
	char *copy;
	int i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!copy)
		return exit_fatal_ptr();
	while (str[i]) {
		copy[i] = str[i];
		++i;
	}
	copy[i] = 0;
	return copy;
}

int add_arg(t_list *cmd, char *arg) {
	char **tmp;
	int i;

	i = 0;
	tmp = 0;
	tmp = (char**)malloc(sizeof(char*) * (cmd->length + 2));
	if (!tmp)
		return exit_fatal();
	while (cmd->args[i]) {
		tmp[i] = cmd->args[i];
		++i;
	}
	if (cmd->length > 0)
		free(cmd->args);
	tmp[i++] = ft_strdup(arg);
	tmp[i] = 0;
	cmd->args = tmp;
	cmd->length++;
	return (EXIT_SUCCESS);
}

int list_push(t_list **list, char *arg) {
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
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
	while (*list && (*list)->prev)
		*list = (*list)->prev;
	return EXIT_SUCCESS;
}

int parse_arg(t_list **cmds, char *arg) {
	int is_break = 0;

	if (strcmp(";", arg) == 0)
		is_break = 1;

	if (is_break && !*cmds)
		return EXIT_SUCCESS;
	else if (!is_break && (!*cmds || (*cmds)->type > TYPE_END))
		return list_push(cmds, arg);
	else if (strcmp("|", arg) == 0)
		(*cmds)->type = TYPE_PIPE;
	else if (is_break)
		(*cmds)->type = TYPE_BREAK;
	else
		return add_arg(*cmds, arg);
	return EXIT_SUCCESS;
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
			return exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		return exit_fatal();
	else if (pid == 0) {
		if (cmd->type == TYPE_PIPE && dup2(cmd->pipe[SIDE_IN], STDOUT) < 0)
			return exit_fatal();
		if (cmd->prev && cmd->prev->type == TYPE_PIPE && dup2(cmd->prev->pipe[SIDE_OUT], STDIN) < 0)
			return exit_fatal();
		if ((ret = execve(cmd->args[0], cmd->args, env)) < 0) {
			show_error("error: cannnot execute ");
			show_error(cmd->args[0]);
			show_error("\n");
		}
		exit(ret);
	}
	else {
		waitpid(pid, &status, 0);
		if (pipe_open) {
			close(cmd->pipe[SIDE_IN]);
			if (!cmd->next || cmd->type == TYPE_BREAK)
				close(cmd->pipe[SIDE_OUT]);
		}
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			close(cmd->prev->pipe[SIDE_OUT]);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return ret;
}

int exec_cmds(t_list **cmds, char **envp) {
	t_list *crt;
	int ret;

	ret = EXIT_SUCCESS;
	list_rewind(cmds);
	while (*cmds) {
		crt = *cmds;
		if (strcmp("cd", crt->args[0]) == 0) {
			ret = EXIT_SUCCESS;
			if (crt->length < 2)
				ret = show_error("error: cd: bad arguments\n");
			else if (chdir(crt->args[1])) {
				ret = show_error("error: cd: cannot change directory to ");
				show_error(crt->args[1]);
				show_error("\n");
			}
		}
		else
			ret = exec_cmd(crt, envp);
		if (!(*cmds)->next)
			break;
		*cmds = (*cmds)->next;
	}
	return ret;
}

int main(int argc, char **argv, char **envp) {
	t_list *cmds;
	int i;
	int ret;

	ret = EXIT_SUCCESS;
	cmds = 0;
	i = 1;
	while (i < argc) {
		parse_arg(&cmds, argv[i]);
		++i;
	}
	if (cmds)
		ret = exec_cmds(cmds, envp);
	return ret;
}
