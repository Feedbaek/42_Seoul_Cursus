/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 05:30:44 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 14:57:58 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isnumeric(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str - '0' >= 0) && (*str - '0' <= 9))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (!*str)
		return (result % 256);
	else
		return (ERROR);
}

void	free_dp(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	free_redir(t_redir *redir)
{
	t_redir	*before_redir;

	while (redir != NULL)
	{
		if (redir->file)
			free(redir->file);
		if (redir->inputs)
			free_dp(redir->inputs);
		before_redir = redir;
		redir = redir->next;
		free(before_redir);
	}
}

void	free_list(t_list *cmds)
{
	t_list	*cur_cmd;
	t_list	*before_cmd;
	t_cmd	*cmd;

	cur_cmd = cmds->next;
	while (cur_cmd != NULL)
	{
		cmd = (t_cmd *)cur_cmd->content;
		if (cmd->cmdline)
			free(cmd->cmdline);
		free_dp(cmd->cmdlines);
		free_redir(cmd->input);
		free_redir(cmd->dinput);
		free_redir(cmd->output);
		before_cmd = cur_cmd;
		cur_cmd = cur_cmd->next;
		free(before_cmd);
		free(cmd);
	}
}

void	close_fd(t_cmd *cmd)
{
	if (cmd->dup_in != -1)
	{
		close(STDIN);
		dup2(cmd->dup_in, STDIN);
		close(cmd->dup_in);
	}
	if (cmd->dup_out != -1)
	{
		close(STDOUT);
		dup2(cmd->dup_out, STDOUT);
		close(cmd->dup_out);
	}
}
