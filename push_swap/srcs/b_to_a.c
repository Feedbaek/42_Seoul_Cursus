/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:06:26 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/11 19:15:28 by minskim2         ###   ########.fr       */
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

static	void	sort_3(t_inform *inform)
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

//static	int	check_pivot(t_inform *inform, int pivot, int size)
//{
//	int	i;

//	i = 0;
//	while (i < size)
//	{
//		if (inform->stack_b[i] >= pivot)
//			return (0);
//		i++;
//	}
//	return (1);
//}

void	b_to_a(t_inform *inform, int size)
{
	int	big_pivot;
	int	small_pivot;
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pa;


	if (is_sorted(inform->stack_b, size, 1))
	{
		while (size-- > 0)
			pa(inform);
		return ;
	}
	if (size <= 3)
	{
		if (size == 3)
			sort_3(inform);
		else if (size == 2 && inform->stack_b[0] < inform->stack_b[1])
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
		//if (check_pivot(inform, small_pivot, size + 1))
		//	break ;
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
