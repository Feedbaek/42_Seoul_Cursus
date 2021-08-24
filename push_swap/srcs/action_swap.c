/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:51:36 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/25 00:04:27 by minskim2         ###   ########.fr       */
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
	ft_putstr("sa\n");
}

void	sb(t_inform *inform)
{
	int	tmp;

	if (inform->size_b < 2)
		return ;
	tmp = inform->stack_a[0];
	inform->stack_a[0] = inform->stack_a[1];
	inform->stack_a[1] = tmp;
	ft_putstr("sb\n");
}

void	ss(t_inform *inform)
{
	sa(inform);
	sb(inform);
	ft_putstr("ss\n");
}
