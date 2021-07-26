/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 01:57:54 by minskim2          #+#    #+#             */
/*   Updated: 2021/07/26 16:00:35 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	path_split(char **envp, t_cmd *x)
{
	char	*path;
	char	*tmp;
	char	**parser;

	while (*envp && ft_strncmp(*envp, "PATH", 4))
		envp++;
	if (!(*envp))
		return (0);
	path = *envp;
	x->path = ft_split(path + 5, ':');
	if (!(x->path))
		return (0);
	parser = x->path;
	while (*parser)
	{
		tmp = *parser;
		*parser = ft_strjoin(*parser, "/");
		parser++;
		free(tmp);
	}
	return (1);
}

int	path_finder(char **envp, t_cmd *x, char*split)
{
	int		mode;
	char	**parser;

	mode = F_OK | X_OK;
	if (!path_split(envp, x))
		return (0);
	parser = x->path;
	while (*parser)
	{
		x->cmd = ft_strjoin(*parser, split);
		if (!access(x->cmd, mode))
			return (1);
		free(x->cmd);
		parser++;
	}
	return (0);
}
