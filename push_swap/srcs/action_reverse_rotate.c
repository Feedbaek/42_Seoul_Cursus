/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:46:53 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 21:30:28 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rra(t_inform *inform)
{
	int	tmp;
	int	idx;

	if (inform->size_a < 2)
		return ;
	idx = inform->size_a - 1;
	tmp = inform->stack_a[idx];
	while (idx > 0)
	{
		inform->stack_a[idx] = inform->stack_a[idx - 1];
		idx--;
	}
	inform->stack_a[0] = tmp;
	if (inform->r && inform->checker)
		ft_putstr("rra\n");
}

void	rrb(t_inform *inform)
{
	int	tmp;
	int	idx;

	if (inform->size_b < 2)
		return ;
	idx = inform->size_b - 1;
	tmp = inform->stack_b[idx];
	while (idx > 0)
	{
		inform->stack_b[idx] = inform->stack_b[idx - 1];
		idx--;
	}
	inform->stack_b[0] = tmp;
	if (inform->r && inform->checker)
		ft_putstr("rrb\n");
}

void	rrr(t_inform *inform)
{
	inform->r = 0;
	rra(inform);
	rrb(inform);
	if (inform->checker)
		ft_putstr("rrr\n");
	inform->r = 1;
}
