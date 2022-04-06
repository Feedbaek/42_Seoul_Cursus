/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 01:57:54 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/05 22:08:38 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	path_split(char **envp, t_cmd *x)
{
	char	*path;
	char	*tmp;
	char	**parser;

	while (*envp && minskim2_strncmp(*envp, "PATH", 4))
		envp++;
	if (!(*envp))
		return (0);
	path = *envp;
	x->path = minskim2_split(path + 5, ':');
	if (!(x->path))
		return (0);
	parser = x->path;
	while (*parser)
	{
		tmp = *parser;
		*parser = minskim2_strjoin(*parser, "/");
		if (!*parser)
			return (0);
		parser++;
		free(tmp);
	}
	return (1);
}

int	path_finder(char **envp, t_cmd *x, char*split)
{
	int			mode;
	char		**parser;
	struct stat	sta;

	if (!path_split(envp, x))
		return (0);
	if (equals(split, ""))
	{
		x->cmd = ft_strdup("");
		return (0);
	}
	parser = x->path;
	while (*parser)
	{
		x->cmd = minskim2_strjoin(*parser, split);
		if (!x->cmd)
			return (0);
		if (!stat(x->cmd, &sta))
			return (1);
		free(x->cmd);
		parser++;
	}
	x->cmd = ft_strdup(split);
	return (0);
}
