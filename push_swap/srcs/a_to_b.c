/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:17:50 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/11 16:00:27 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	call_rrr(t_inform *inform, int cnt_ra, int cnt_rb)
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

void	a_to_b(t_inform *inform, int size)
{
	int	big_pivot;
	int	small_pivot;
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pb;

	if (size < 3)
	{
		if (size == 2 && inform->stack_a[0] > inform->stack_a[1])
			sa(inform);
		return ;
	}
	cnt_ra = 0;
	cnt_pb = 0;
	cnt_rb = 0;
	find_pivot_2(inform->stack_a, size, &big_pivot, &small_pivot);
	while (0 < size--)
	{
		if (inform->stack_a[0] >= big_pivot)
		{
			ra(inform);
			cnt_ra++;
		}
		else
		{
			pb(inform);
			cnt_pb++;
			if (inform->stack_b[0] < small_pivot)
			{
				rb(inform);
				cnt_rb++;
			}
		}
	}
	call_rrr(inform, cnt_ra, cnt_rb);
	a_to_b(inform, cnt_ra);
	b_to_a(inform, cnt_pb);
	//b_to_a(inform, cnt_pb - cnt_rb);
}

void	b_to_a(t_inform *inform, int size)
{
	int	big_pivot;
	int	small_pivot;
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pa;


	if (size < 3)
	{
		if (size == 2 && inform->stack_b[0] < inform->stack_b[1])
			sb(inform);
		while (size-- > 0)
			pa(inform);
		return ;
	}
	cnt_ra = 0;
	cnt_pa = 0;
	cnt_rb = 0;
	find_pivot_2(inform->stack_b, size, &big_pivot, &small_pivot);
	while (0 < size--)
	{
		if (inform->stack_b[0] < small_pivot)
		{
			rb(inform);
			cnt_rb++;
		}
		else
		{
			pa(inform);
			cnt_pa++;
			if (inform->stack_a[0] < big_pivot)
			{
				ra(inform);
				cnt_ra++;
			}
		}
	}
	a_to_b(inform, cnt_pa - cnt_ra);
	call_rrr(inform, cnt_ra, cnt_rb);
	a_to_b(inform, cnt_ra);
	b_to_a(inform, cnt_rb);
}
