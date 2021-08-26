/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:06:34 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/26 13:43:15 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_inform *inform)
{
	int	idx;
	int	tmp;

	if (inform->size_a < 2)
		return ;
	idx = 0;
	tmp = inform->stack_a[0];
	while (idx < inform->size_a - 1)
	{
		inform->stack_a[idx] = inform->stack_a[idx + 1];
		idx++;
	}
	inform->stack_a[idx] = tmp;
	if (inform->r)
		ft_putstr("ra\n");
}

void	rb(t_inform *inform)
{
	int	idx;
	int	tmp;

	if (inform->size_b < 2)
		return ;
	idx = 0;
	tmp = inform->stack_b[0];
	while (idx < inform->size_b - 1)
	{
		inform->stack_b[idx] = inform->stack_b[idx + 1];
		idx++;
	}
	inform->stack_b[idx] = tmp;
	if (inform->r)
		ft_putstr("rb\n");
}

void	rr(t_inform *inform)
{
	inform->r = 0;
	ra(inform);
	rb(inform);
	ft_putstr("rr\n");
	inform->r = 1;
}
