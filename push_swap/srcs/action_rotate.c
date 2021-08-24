/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:06:34 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/25 00:04:02 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_inform *inform)
{
	int	tmp;
	int	*parser;

	if (inform->size_a < 2)
		return ;
	tmp = inform->stack_a[0];
	parser = inform->stack_a;
	while (*parser)
	{
		*parser = *(parser + 1);
		parser++;
	}
	inform->stack_a[inform->size_a - 1] = tmp;
	ft_putstr("ra\n");
}

void	rb(t_inform *inform)
{
	int	tmp;
	int	*parser;

	if (inform->size_b < 2)
		return ;
	tmp = inform->stack_b[0];
	parser = inform->stack_b;
	while (*parser)
	{
		*parser = *(parser + 1);
		parser++;
	}
	inform->stack_b[inform->size_b - 1] = tmp;
	ft_putstr("rb\n");
}

void	rr(t_inform *inform)
{
	ra(inform);
	rb(inform);
	ft_putstr("rr\n");
}
