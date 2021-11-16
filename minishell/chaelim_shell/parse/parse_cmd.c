/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 06:11:00 by chalim            #+#    #+#             */
/*   Updated: 2021/08/07 22:19:32 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_var(char *str, char **result)
{
	int		i;
	char	*key;
	char	tmp;

	i = 0;
	*str = 0;
	str++;
	if (*str == '?')
	{
		*result = ft_itoa(g_state.exit_status / 256);
		return (1);
	}
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	tmp = str[i];
	str[i] = 0;
	key = ft_strdup(str);
	str[i] = tmp;
	if (find_value(key))
		*result = ft_strdup(find_value(key));
	else
		*result = ft_strdup("");
	free(key);
	return (i);
}

int	find_dquote(char *str, char **result)
{
	int		i;
	int		jump;
	int		len;
	char	*re;

	i = 0;
	*result = ft_strdup("");
	len = -1;
	while (str[++len] != '\"')
	{
		if (str[len] == '$' && (ft_isalnum(str[len + 1]) || str[len + 1] == \
		'_' || str[len + 1] == '?'))
		{
			jump = find_var(str + len, &re);
			*result = ft_strjoin1(*result, str);
			*result = ft_strjoin2(*result, re);
			str += len + jump + 1;
			i += len + jump + 1;
			len = -1;
		}
	}
	str[len] = 0;
	i += len;
	*result = ft_strjoin1(*result, str);
	return (i + 1);
}

int	change_line(char *str, char **result)
{
	int	i;

	i = 0;
	if (*str == '\'')
	{
		*str = 0;
		str++;
		while (str[i] != '\'')
			i++;
		str[i] = 0;
		*result = ft_strdup(str);
		return (i + 1);
	}
	else if (*str == '$')
		return (find_var(str, result));
	else if (*str == '\"')
	{
		*str = 0;
		str++;
		return (find_dquote(str, result));
	}
	return (0);
}

char	*check_line(char *line)
{
	char	*new;
	char	*str;
	char	*result;
	int		len;
	int		jump;

	str = line;
	new = ft_strdup("");
	len = -1;
	while (str[++len])
	{
		if ((str[len] == '$' && (ft_isalnum(str[len + 1]) || str[len + 1] == \
		'_' || str[len + 1] == '?')) || str[len] == '\'' || str[len] == '\"')
		{
			jump = change_line(str + len, &result);
			new = ft_strjoin1(new, str);
			new = ft_strjoin2(new, result);
			str += len + jump + 1;
			len = -1;
		}
	}
	new = ft_strjoin1(new, str);
	free(line);
	return (new);
}

int	parse_cmd(t_cmd *cmd)
{
	char	**line;

	if (check_redir(cmd))
		return (1);
	cmd->cmdlines = parse_split(cmd->cmdline, ' ');
	line = cmd->cmdlines;
	while (*line)
	{
		*line = check_line(*line);
		line++;
	}
	return (0);
}
