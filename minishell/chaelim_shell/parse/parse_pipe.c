/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 03:46:15 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 16:05:49 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_cmd(t_cmd *cmd, int i, char *s)
{
	if (!s)
		cmd->flag = 0;
	else
		cmd->flag = 1;
	if (i == 0)
		cmd->preflag = 0;
	else
		cmd->preflag = 1;
	cmd->cmdlines = 0;
	cmd->cmdline = 0;
	cmd->fds[0] = 0;
	cmd->fds[1] = 1;
	cmd->input = 0;
	cmd->output = 0;
	cmd->single_double = 0;
	make_redir2(cmd);
	cmd->redir = 0;
	cmd->dup_in = -1;
	cmd->dup_out = -1;
}

int	put_cmds(t_list *cmds, char **cmdline)
{
	int		i;
	t_list	*cur;
	t_cmd	*cmd;

	i = 0;
	while (cmdline[i])
	{
		cmd = (t_cmd *)malloc(sizeof(t_cmd));
		cur = (t_list *)malloc(sizeof(t_list));
		if (!cmd || !cmds)
			print_malloc_error();
		init_cmd(cmd, i, cmdline[i + 1]);
		cmd->cmdline = ft_strtrim(cmdline[i], " ");
		if (!*(cmd->cmdline) && (cmd->flag == 1 || cmd->preflag == 1))
		{
			print_exec_error_1("syntax error near unexpected token `|'");
			return (1);
		}
		cur->content = (char **)cmd;
		cmds->next = cur;
		cur->next = 0;
		cmds = cur;
		i++;
	}
	return (0);
}

int	parse_pipe(char *line, t_list *cmds)
{
	char	**cmdline;
	char	**str;
	int		result;

	if (!line)
		return (1);
	cmdline = parse_split(line, '|');
	if (!cmdline)
	{
		print_exec_error_1("not valid usage of quote or double quote");
		return (1);
	}
	result = put_cmds(cmds, cmdline);
	str = cmdline;
	while (*str)
		free(*str++);
	free(cmdline);
	return (result);
}
