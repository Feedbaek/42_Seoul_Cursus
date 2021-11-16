/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 03:27:30 by chalim            #+#    #+#             */
/*   Updated: 2021/08/08 00:42:19 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(void)
{
	int	i;
	int	j;

	i = 0;
	while ((g_state.envp)[i])
	{
		j = -1;
		while (1)
		{
			j++;
			if ((g_state.envp)[i][j] == '=' || (g_state.envp)[i][j] == 0)
				break ;
		}
		if ((g_state.envp)[i][j] == '=')
			ft_putendl_fd((g_state.envp)[i], STDOUT);
		i++;
	}
	g_state.exit_status = 0;
}
