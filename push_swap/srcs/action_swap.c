/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:51:36 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/25 14:39:10 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sa(t_inform *inform)
{
	int	tmp;

	if (inform->size_a < 2)
		return ;
	tmp = inform->stack_a[0];
	inform->stack_a[0] = inform->stack_a[1];
	inform->stack_a[1] = tmp;
}

void	sb(t_inform *inform)
{
	int	tmp;

	if (inform->size_b < 2)
		return ;
	tmp = inform->stack_a[0];
	inform->stack_a[0] = inform->stack_a[1];
	inform->stack_a[1] = tmp;
}

void	ss(t_inform *inform)
{
	sa(inform);
	sb(inform);
}
