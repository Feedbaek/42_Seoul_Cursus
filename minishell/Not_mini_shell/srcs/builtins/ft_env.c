/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 00:02:00 by sungmcho          #+#    #+#             */
/*   Updated: 2022/04/05 17:56:45 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_env(int flag)
{
	int	i;

	i = -1;
	while (g_state.envp[++i])
		ft_putendl_fd(g_state.envp[i], 1);
	g_state.exit_status = 0;
	if (flag)
		exit(0);
}
