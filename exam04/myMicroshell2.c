#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SIDE_IN		1
#define SIDE_OUT	0

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	0
#define TYPE_PIPE	1
#define TYPE_BREAK	2

typedef struct s_list {
	char **args;
	int length;
	int type;
	int pipe[2];
	struct s_list *prev;
	struct s_list *next;
}	t_list;

int show_error(char *str) {
	if (str)
		write(STDERR, str, ft_strlen(str));
	return EXIT_FAILURE;
}

int exit_fatal() {
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
	return EXIT_FAILURE;
}

void *exit_fatal_ptr() {
	exit_fatal();
	return 0;
}

int ft_strlen(char *str) {
	int i = 0;
	while (str[i]) {
		++i;
	}
	return i;
}

char *ft_strdup(char *str) {
	int i = 0;
	char *copy;

	copy = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!copy)
		return exit_fatal_ptr();
	while (str[i]) {
		copy[i] = str[i];
		++i;
	}
	copy[i] = 0;
	return copy;
}

int add_args(t_list *cmd, char *arg) {
	int i = 0;
	char **tmp;

	tmp = (char**)malloc(sizeof(char*) * (cmd->length + 2));
	if (!tmp)
		return exit_fatal();
	while (cmd->args[i]) {
		tmp[i] = cmd->args[i];
		++i;
	}
	tmp[i++] = ft_strdup(arg);
	tmp[i] = 0;
	if (cmd->length)
		free(cmd->args);
	cmd->args = tmp;
	return EXIT_SUCCESS;
}

int list_push(t_list **cmds, char argv) {
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return exit_fatal();
	new->args = 0;
	new->length = 0;
	new->type = TYPE_END;
	new->prev = 0;
	new->next = 0;
	if (*cmds) {
		(*cmds)->next = new;
		new->prev = *cmds;
	}
	*cmds = new;
	add_args(*cmds, argv);
}

int parse_argv(t_list **cmds, char *argv) {
	int is_break = 0;
	if (strcmp(argv, ";") == 0)
		is_break = 1;
	if (is_break || !(*cmds))
		return EXIT_SUCCESS;
	else if (!is_break && (!(*cmds) || (*cmds)->type > TYPE_END))
		return list_push(cmds, argv);
	else if (strcmp(argv, "|") == 0)
		(*cmds)->type = TYPE_PIPE;
	else if (is_break)
		(*cmds)->type = TYPE_BREAK;
	else
		add_args(*cmds, argv);
	return EXIT_SUCCESS;
}

int rewind(t_list **cmds) {
	while (*cmds && (*cmds)->prev) {
		*cmds = (*cmds)->prev;
	}
	return EXIT_SUCCESS;
}

int exec_cmd(t_list *cmd, char envp) {
	pid_t pid;
	int status;
	int ret;
	int pipe_open = 0;

	if (cmd->type == TYPE_PIPE || (cmd->prev && cmd->prev->type == TYPE_PIPE)) {
		pipe_open = 1;
		if (pipe(cmd->pipe) < 0)
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		return exit_fatal();
	else if (pid == 0) {
		if (cmd->type == TYPE_PIPE && dup2(cmd->pipe[SIDE_IN], STDOUT) < 0)
			return exit_fatal();
		if (cmd->prev->type == TYPE_PIPE && dup2(cmd->pipe[SIDE_OUT], STDIN) < 0)
			return exit_fatal();
		if ((ret = execve(cmd->args[0], cmd->args, envp)) < 0) {
			show_error("error: cannot execute ");
			show_error(cmd->args[0]);
			show_error("\n");
		}
		exit(ret);
	}
	else {
		if ()
	}
}

int exec_cmds(t_list **cmds, char envp) {
	t_list *crt;
	int i = 0;
	int ret = EXIT_SUCCESS;

	rewind(cmds);
	while (*cmds) {
		ret = EXIT_SUCCESS;
		crt = *cmds;
		if (strcmp(crt->args[0], "cd") == 0) {
			if (crt->length < 2) {
				show_error("error: cd: bad arguments\n");
				ret = EXIT_FAILURE;
			}
			else {
				if (chdir(crt->args[1]) < 0) {
					ret = show_error("error: cd: cannot change directory to ");
					show_error(crt->args[1]);
					show_error("\n");
				}
			}
		}
		else
			exec_cmd(*cmds, envp);
	}
}

int main(int argc, char **argv, char **envp) {
	t_list *cmds = 0;
	int ret = EXIT_SUCCESS;
	int i = 1;
	while (argv[i] < argc) {
		parse_argv(&cmds, argv[i]);
	}
	if (cmds)
		ret = exec_cmds(cmds, envp);
	return ret;
}
