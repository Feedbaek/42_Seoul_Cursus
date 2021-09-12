/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:17:50 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/12 17:52:37 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	call_rrr(t_inform *inform, int cnt_ra, int cnt_rb)
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

static	void	sort_3(t_inform *inform)
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

static	int	check_pivot(t_inform *inform, int pivot, int size)
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

void	a_to_b(t_inform *inform, int size)
{
	int	big_pivot;
	int	small_pivot;
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pb;
	int	cnt_skip;

	if (is_sorted(inform->stack_a, size, 0))
		return ;
	if (size <= 3)
	{
		if (size == 3)
			sort_3(inform);
		else if (size == 2 && inform->stack_a[0] > inform->stack_a[1])
			sa(inform);
		return ;
	}
	cnt_ra = 0;
	cnt_pb = 0;
	cnt_rb = 0;
	cnt_skip = 0;
	find_pivot_2(inform->stack_a, size, &big_pivot, &small_pivot);
	while (0 < size--)
	{
		if (check_pivot(inform, big_pivot, size + 1))
		{
			cnt_skip = size + 1;
			break ;
		}
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
	a_to_b(inform, cnt_ra + cnt_skip);
	b_to_a(inform, cnt_pb);
	//b_to_a(inform, cnt_pb - cnt_rb);
}
