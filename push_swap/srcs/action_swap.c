/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:51:36 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 21:27:37 by minskim2         ###   ########.fr       */
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
	if (inform->r && inform->checker)
		ft_putstr("sa\n");
}

void	sb(t_inform *inform)
{
	int	tmp;

	if (inform->size_b < 2)
		return ;
	tmp = inform->stack_b[0];
	inform->stack_b[0] = inform->stack_b[1];
	inform->stack_b[1] = tmp;
	if (inform->r && inform->checker)
		ft_putstr("sb\n");
}

void	ss(t_inform *inform)
{
	inform->r = 0;
	sa(inform);
	sb(inform);
	if (inform->checker)
		ft_putstr("ss\n");
	inform->r = 1;
}
