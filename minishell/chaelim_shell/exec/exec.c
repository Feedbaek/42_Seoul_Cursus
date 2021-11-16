/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 23:44:34 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 21:54:08 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_builtins(t_cmd *cmd)
{
	char	*tmp;

	tmp = cmd->cmdlines[0];
	if (!ft_strncmp(tmp, "cd\0", ft_strlen(tmp) + 1))
		ft_cd(cmd);
	else if (!ft_strncmp(tmp, "export\0", ft_strlen(tmp) + 1))
		ft_export(cmd);
	else if (!ft_strncmp(tmp, "unset\0", ft_strlen(tmp) + 1))
		ft_unset(cmd);
	else if (!ft_strncmp(tmp, "pwd\0", ft_strlen(tmp) + 1))
		ft_pwd();
	else if (!ft_strncmp(tmp, "exit\0", ft_strlen(tmp) + 1))
		ft_exit(cmd);
	else if (!ft_strncmp(tmp, "env\0", ft_strlen(tmp) + 1))
		ft_env();
	else if (!ft_strncmp(tmp, "echo\0", ft_strlen(tmp) + 1))
		ft_echo(cmd);
	else
		return (0);
	return (1);
}

char	*find_path(char *cmd)
{
	int			i;
	char		*tmp;
	char		**paths;
	struct stat	sta;

	tmp = find_value("PATH");
	if (!tmp)
		return (ft_strdup(cmd));
	paths = ft_split(tmp, ':');
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin("/", cmd);
		paths[i] = ft_strjoin2(paths[i], tmp);
		if (stat(paths[i], &sta) == 0)
		{
			tmp = ft_strdup(paths[i]);
			free_dp(paths);
			return (tmp);
		}
	}
	free_dp(paths);
	return (ft_strdup(cmd));
}

int	exec_child(t_cmd *cur, int fd)
{
	char	*path;

	if (cur->flag == 1 && cur->dup_out == -1)
	{
		dup2(fd, STDOUT);
		close(fd);
	}
	if (cur->fds[0] != 0 && cur->dup_out == -1)
	{
		dup2(cur->fds[0], STDIN);
		close(cur->fds[0]);
	}
	path = find_path(cur->cmdlines[0]);
	if (!exec_builtins(cur))
		g_state.exit_status = execve(path, cur->cmdlines, g_state.envp);
	if (g_state.exit_status != 0)
		print_exec_error_2(cur->cmdlines[0], "command not found");
	exit(g_state.exit_status);
}

void	exec_pipe(t_list *cur, t_cmd *cmd)
{
	t_cmd	*next;
	int		pid;
	int		fd;

	fd = -1;
	next = (t_cmd *)cur->content;
	if (cmd->flag == 1 && cmd->dup_out == -1)
	{
		next = (t_cmd *)cur->next->content;
		pipe(next->fds);
		fd = next->fds[1];
	}
	pid = fork();
	if (pid == 0)
		exec_child(cmd, fd);
	waitpid(pid, &(g_state.exit_status), 0);
	if (cmd->flag == 1)
		close(next->fds[1]);
	if (cmd->fds[0] != 0)
		close(cmd->fds[0]);
}

void	exec_start(t_list *cmds)
{
	t_list	*cur_cmd;
	t_cmd	*cmd;

	cur_cmd = cmds->next;
	while (cur_cmd != NULL)
	{
		cmd = (t_cmd *)cur_cmd->content;
		if (parse_cmd(cmd))
		{
			print_exec_error_1("syntax error near unexpected token `newline'");
			g_state.exit_status = 258;
		}
		else if (cmd->cmdlines[0])
		{
			exec_redir(cmd);
			if (g_state.stop)
				g_state.stop = 0;
			else if ((cmd->flag | cmd->preflag) == 1 || exec_builtins(cmd) == 0)
				exec_pipe(cur_cmd, cmd);
		}
		cur_cmd = cur_cmd->next;
		close_fd(cmd);
	}
	free_list(cmds);
	cmds->next = 0;
}
