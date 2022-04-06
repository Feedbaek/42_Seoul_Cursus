/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:18:04 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/03 16:18:05 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	add_envp(char *s)
{
	int		i;
	int		len;
	char	**tmp;

	i = -1;
	len = two_ptr_counter(g_state.envp);
	tmp = (char **)malloc(sizeof(char *) * (len + 2));
	if (!tmp)
		malloc_error();
	while (g_state.envp[++i])
		tmp[i] = g_state.envp[i];
	tmp[i++] = ft_strdup(s);
	tmp[i] = NULL;
	free(g_state.envp);
	g_state.envp = tmp;
}

void	do_export(char *k, char *s)
{
	int	idx;

	idx = get_envp_idx(g_state.envp, k);
	if (idx < 0)
		add_envp(s);
	else
	{
		free(g_state.envp[idx]);
		g_state.envp[idx] = ft_strdup(s);
	}
}
