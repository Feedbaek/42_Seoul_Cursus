/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:01:22 by sungmcho          #+#    #+#             */
/*   Updated: 2022/03/10 16:36:40 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_double_pointer(char ***tab)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *tab;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
