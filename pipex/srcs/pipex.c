/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 23:26:08 by minskim2          #+#    #+#             */
/*   Updated: 2021/07/25 03:25:34 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void connect_pipe(int pipefd[2], int fd)
{
	dup2(pipefd[fd], fd);
	close(pipefd[fd]);
}

static void cmd_init(const char *line, t_cmd *cmd, char **envp)
{
	char	**split;

	cmd->path = path_finder(envp, cmd);
	split = ft_split(line, ' ');
	cmd->cmd = ft_strjoin("/bin/", split[0]);
	cmd->argv = split;
}

static void parent_proc(char **argv, char **envp, t_cmd *cmd_arg)
{
	redirect_out(OUT_FILE);
	connect_pipe(pipefd, STDIN_FILENO);
	cmd_init(CMD_2, cmd_arg, envp);
	if (execve(cmd_arg->cmd, cmd_arg->argv, cmd_arg->path) == -1)
		perror(cmd_arg->cmd);
}

int	main(int argc, char const **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid;
	t_cmd	cmd_arg;

	if (argc != 5)
		return (0);
	pipe(pipefd);
	pid = fork();
	if (pid != 0)
	{
		parent_proc(argv, envp, &cmd_arg);
	}
	else
	{
		redirect_in(IN_FILE);
		connect_pipe(pipefd, STDOUT_FILENO);
		cmd_init(CMD_1, &cmd_arg);
		if (execve(cmd_arg.cmd, cmd_arg.argv, cmd_arg.path) == -1)
			perror(cmd_arg.cmd);
	}
	return (0);
}
