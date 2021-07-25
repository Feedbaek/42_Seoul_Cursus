/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 23:26:08 by minskim2          #+#    #+#             */
/*   Updated: 2021/07/25 19:26:33 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void connect_pipe(int pipefd[2], int fd)
{
	dup2(pipefd[fd], fd);
	close(pipefd[0]);
	close(pipefd[1]);
}

static void cmd_init(const char *line, t_cmd *x, char **envp)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!path_finder(envp, x, split[0]))
		perror("init error");
	x->argv = split;
}

static void parent_proc(char **argv, char **envp, t_cmd *cmd_arg)
{
	redirect_out(OUT_FILE);
	connect_pipe(cmd_arg->pipe, STDIN_FILENO);
	cmd_init(CMD_2, cmd_arg, envp);
	if (execve(cmd_arg->cmd, cmd_arg->argv, envp) == -1)
		perror("parent error");
}

static void child_proc(char **argv, char **envp, t_cmd *cmd_arg)
{
	redirect_in(IN_FILE);
	connect_pipe(cmd_arg->pipe, STDOUT_FILENO);
	cmd_init(CMD_1, cmd_arg, envp);
	if (execve(cmd_arg->cmd, cmd_arg->argv, envp) == -1)
		perror("child error");
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	t_cmd	cmd_arg;
	int		status;

	if (argc != 5)
		return (0);
	pipe(cmd_arg.pipe);
	pid = fork();
	if (pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status) == 0)
			exit(1);
		parent_proc(argv, envp, &cmd_arg);
	}
	else
	{
		child_proc(argv, envp, &cmd_arg);
	}
	return (0);
}
