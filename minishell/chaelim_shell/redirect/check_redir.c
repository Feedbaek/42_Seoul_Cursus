/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 05:19:43 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 21:16:13 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_var(char *str, int *len, t_redir *new, int *jump)
{
	char	*re;

	re = 0;
	*len += find_var(str + *len, &re) + 1;
	str[*len] = 0;
	new->file = ft_strjoin1(new->file, str);
	new->file = ft_strjoin2(new->file, re);
	str += *len + 1;
	*jump += *len;
	*len = -1;
}

int	find_file(char *str, t_redir *new)
{
	int		jump;
	int		len;
	char	c;

	jump = 0;
	len = 0;
	while (*(++str) == ' ')
		jump++;
	if (*str == 0)
		return (-3);
	new->file = ft_strdup("");
	while (!(str[len] == ' ' || str[len] == 0))
	{
		if (str[len] == '$' && (ft_isalnum(str[len + 1]) || \
		str[len + 1] == '_' || str[len + 1] == '?'))
			put_var(str, &len, new, &jump);
		len++;
	}
	jump += len;
	c = str[len];
	str[len] = 0;
	new->file = ft_strjoin1(new->file, str);
	str[len] = c;
	return (jump);
}

int	find_file2(char *str, t_redir *new)
{
	int		jump;
	int		len;
	char	c;

	jump = 0;
	len = 0;
	while (*(++str) == ' ')
		jump++;
	if (*str == 0)
		return (-3);
	new->file = ft_strdup("");
	while (!(str[len] == ' ' || str[len] == 0))
		len++;
	jump += len;
	c = str[len];
	str[len] = 0;
	new->file = ft_strjoin1(new->file, str);
	str[len] = c;
	new->index += 1;
	put_inputs(new);
	return (jump);
}

int	find_redir(char *str, t_cmd *cmd)
{
	t_redir	*new;

	if (*str == '>')
	{
		new = make_redir(&(cmd->output));
		if (*(str + 1) == '>')
			new->doub = true;
	}
	else
	{
		cmd->single_double = 0;
		if (*(str + 1) == '<')
		{
			*str = 0;
			cmd->single_double = 1;
			return (find_file2(str + 1, cmd->dinput) + 1);
		}
		else
			new = make_redir(&(cmd->input));
	}
	*str = 0;
	if (new->doub)
		return (find_file(str + 1, new) + 1);
	return (find_file(str, new));
}

int	check_redir(t_cmd *cmd)
{
	char	*new;
	char	*str;
	int		len;
	int		jump;

	str = cmd->cmdline;
	new = ft_strdup("");
	len = check_quote(str);
	while (str[len] == '>' || str[len] == '<')
	{
		cmd->redir = 1;
		jump = find_redir(str + len, cmd);
		if (jump < 0)
		{
			free(new);
			return (1);
		}
		new = ft_strjoin1(new, str);
		str += len + jump + 1;
		len = check_quote(str);
	}
	new = ft_strjoin1(new, str);
	free(cmd->cmdline);
	cmd->cmdline = new;
	return (0);
}
