/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:57:06 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 21:16:11 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redir_output(char *file, t_cmd *cmd)
{
	int	fd;

	if (cmd->dup_out != -1)
	{
		close(STDOUT);
		dup2(cmd->dup_out, STDOUT);
		close(cmd->dup_out);
	}
	cmd->dup_out = dup(STDOUT);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (fd < 0)
	{
		print_exec_error_2(file, strerror(errno));
		errno = 0;
	}
	dup2(fd, STDOUT);
	close(fd);
	return ;
}

void	redir_doutput(char *file, t_cmd *cmd)
{
	int	fd;

	if (cmd->dup_out != -1)
	{
		close(STDOUT);
		dup2(cmd->dup_out, STDOUT);
		close(cmd->dup_out);
	}
	cmd->dup_out = dup(STDOUT);
	fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0744);
	if (fd < 0)
	{
		print_exec_error_2(file, strerror(errno));
		errno = 0;
	}
	dup2(fd, STDOUT);
	close(fd);
	return ;
}

void	redir_input(char *file, t_cmd *cmd)
{
	int	fd;

	if (cmd->dup_in != -1)
	{
		close(STDIN);
		dup2(cmd->dup_in, STDIN);
		close(cmd->dup_in);
	}
	fd = open(file, O_RDONLY, 0644);
	if (fd < 0)
	{
		print_exec_error_2(file, strerror(errno));
		g_state.stop = 1;
		g_state.exit_status = 1;
		errno = 0;
	}
	cmd->dup_in = dup(STDIN);
	dup2(fd, STDIN);
	close(fd);
	return ;
}

void	redir_dinput(t_cmd *cmd)
{
	int		fd;
	int		i;

	if (cmd->dinput->index == 0)
		return ;
	i = 0;
	fd = open("./.temp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		prepare_token_and_cmd(&g_state);
		prompt3(&g_state);
		i = use_temp(cmd, fd, i);
		if (i == cmd->dinput->index)
			break ;
	}
	close(fd);
}

void	exec_redir(t_cmd *cmd)
{
	t_redir	*tmp;

	redir_dinput(cmd);
	tmp = cmd->input;
	while (tmp && !g_state.stop)
	{
		redir_input(tmp->file, cmd);
		tmp = tmp->next;
	}
	if (cmd->single_double)
		redir_input("./.temp", cmd);
	if (cmd->dinput->index)
		clear_temp();
	tmp = cmd->output;
	while (tmp)
	{
		if (tmp->doub)
			redir_doutput(tmp->file, cmd);
		else
			redir_output(tmp->file, cmd);
		tmp = tmp->next;
	}
}
