/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_b_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:55:20 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 19:45:50 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	b_to_a_call_rrr(t_inform *inform, int cnt_ra, int cnt_rb)
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

void	b_to_a_sort_3(t_inform *inform)
{
	if (is_sorted(inform->stack_b, 3, 1))
		return ;
	if (inform->stack_b[0] > inform->stack_b[1])
	{
		rb(inform);
		sb(inform);
		rrb(inform);
		if (inform->stack_b[0] < inform->stack_b[1])
			sb(inform);
	}
	else
	{
		sb(inform);
		if (inform->stack_b[1] < inform->stack_b[2])
		{
			rb(inform);
			sb(inform);
			rrb(inform);
			if (inform->stack_b[0] < inform->stack_b[1])
				sb(inform);
		}
	}
}

int	b_to_a_check_pivot(t_inform *inform, int pivot, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (inform->stack_b[i] > pivot)
			return (0);
		i++;
	}
	return (1);
}

void	b_to_a_init_cnt(t_param *param)
{
	param->cnt_ra = 0;
	param->cnt_pa = 0;
	param->cnt_rb = 0;
	param->cnt_skip = 0;
	param->check_rr = 0;
}

int	set_b_to_a(t_inform *inform, t_param *param, int size)
{
	if (is_sorted(inform->stack_b, size, 1))
	{
		while (size-- > 0)
			pa(inform);
		return (1);
	}
	if (size <= 3)
	{
		if (size == 3)
			b_to_a_sort_3(inform);
		else if (size == 2 && inform->stack_a[0] < inform->stack_a[1])
			sb(inform);
		while (size-- > 0)
			pa(inform);
		return (1);
	}
	b_to_a_init_cnt(param);
	find_pivot_2(inform->stack_b, size, &param->big_pivot, &param->small_pivot);
	return (0);
}
