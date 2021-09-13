/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_a_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:43:04 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 19:36:09 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	a_to_b_call_rrr(t_inform *inform, int cnt_ra, int cnt_rb)
{
	int	i;
	int	num_rrr;

	num_rrr = cnt_ra;
	if (cnt_ra > cnt_rb)
		num_rrr = cnt_rb;
	i = 0;
	while (i++ < num_rrr)
		rrr(inform);
	i = 0;
	while (i++ < cnt_ra - num_rrr)
		rra(inform);
	i = 0;
	while (i++ < cnt_rb - num_rrr)
		rrb(inform);
}

void	a_to_b_sort_3(t_inform *inform)
{
	if (is_sorted(inform->stack_a, 3, 0))
		return ;
	if (inform->stack_a[0] < inform->stack_a[1])
	{
		ra(inform);
		sa(inform);
		rra(inform);
		if (inform->stack_a[0] > inform->stack_a[1])
			sa(inform);
	}
	else
	{
		sa(inform);
		if (inform->stack_a[1] > inform->stack_a[2])
		{
			ra(inform);
			sa(inform);
			rra(inform);
			if (inform->stack_a[0] > inform->stack_a[1])
				sa(inform);
		}
	}
}

int	a_to_b_check_pivot(t_inform *inform, int pivot, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (inform->stack_a[i] < pivot)
			return (0);
		i++;
	}
	return (1);
}

void	a_to_b_init_cnt(t_param *param)
{
	param->cnt_ra = 0;
	param->cnt_pb = 0;
	param->cnt_rb = 0;
	param->cnt_skip = 0;
	param->check_rr = 0;
}

int	set_a_to_b(t_inform *inform, t_param *param, int size)
{
	if (is_sorted(inform->stack_a, size, 0))
		return (1);
	if (size <= 3)
	{
		if (size == 3)
			a_to_b_sort_3(inform);
		else if (size == 2 && inform->stack_a[0] > inform->stack_a[1])
			sa(inform);
		return (1);
	}
	a_to_b_init_cnt(param);
	find_pivot_2(inform->stack_a, size, &param->big_pivot, &param->small_pivot);
	return (0);
}
