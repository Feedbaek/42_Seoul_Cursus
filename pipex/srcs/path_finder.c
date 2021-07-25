/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 01:57:54 by minskim2          #+#    #+#             */
/*   Updated: 2021/07/25 03:25:32 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	path_finder(char **envp, t_cmd *x)
{
	char	*path;

	while (*envp && ft_strncmp(*envp, "PATH", 4))
		++envp;
	if (!(*envp))
		return (0);
	path = *envp;
	x->path = ft_split(path + 5, ':');
	if (!(x->path))
		return (0);
	return (1);
}
