/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 23:26:08 by minskim2          #+#    #+#             */
/*   Updated: 2021/07/27 17:21:49 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	connect_pipe(int pipefd[2], int fd)
{
	dup2(pipefd[fd], fd);
	close(pipefd[0]);
	close(pipefd[1]);
}

static void	cmd_init(const char *line, t_cmd *x, char **envp)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!path_finder(envp, x, split[0]))
	{
		perror("init error");
		exit(1);
	}
	x->argv = split;
}

static void	parent_proc(char **argv, char **envp, t_cmd *cmd_arg)
{
	redirect_out(argv[4]);
	connect_pipe(cmd_arg->pipe, STDIN_FILENO);
	cmd_init(argv[3], cmd_arg, envp);
	waitpid(cmd_arg->pid, &(cmd_arg->status), WNOWAIT);
	if (execve(cmd_arg->cmd, cmd_arg->argv, envp) == -1)
	{
		perror("parent error");
		exit(1);
	}
}

static void	child_proc(char **argv, char **envp, t_cmd *cmd_arg)
{
	redirect_in(argv[1]);
	connect_pipe(cmd_arg->pipe, STDOUT_FILENO);
	cmd_init(argv[2], cmd_arg, envp);
	if (execve(cmd_arg->cmd, cmd_arg->argv, envp) == -1)
	{
		perror("child error");
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd_arg;

	if (argc != 5)
		return (0);
	pipe(cmd_arg.pipe);
	cmd_arg.pid = fork();
	if (cmd_arg.pid > 0)
	{
		parent_proc(argv, envp, &cmd_arg);
	}
	else
	{
		child_proc(argv, envp, &cmd_arg);
	}
	return (0);
}
