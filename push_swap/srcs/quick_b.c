/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:09:52 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/09 19:40:31 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	int	is_sorted_b(int *stack, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (stack[i] < stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// 312	rb 12-3 sb 21-3 rrb 321
// 213	rb 13-2 sb 31-2 rrb 231 sb 321

// 231	sb 321
// 132	sb 312 rb 12-3 sb 21-3 rrb 321
// 123	sb 213 rb 13-2 sb 31-2 rrb 231 sb 321

static	void	sort_3(t_inform *inform)
{
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

static	int	quick_sort_end(t_inform *inform, int size)
{
	if (is_sorted_b(inform->stack_b, size) || size < 2)
		return (1);
	if (size == 2 && inform->stack_b[0] < inform->stack_b[1])
	{
		sb(inform);
		return (1);
	}
	if (size == 3)
	{
		sort_3(inform);
		return (1);
	}
	return (0);
}

static	void	partition(t_inform *inform, int size, int *cnt_push)
{
	int	pivot;
	int	i;

	pivot = find_pivot(inform->stack_b, size);
	i = 0;
	while (i < size)
	{
		if (inform->stack_b[0] > pivot)
		{
			pa(inform);
			(*cnt_push)++;
		}
		else
			rb(inform);
		i++;
	}
	i = 0;
	while (i < size - *cnt_push)
	{
		rrb(inform);
		i++;
	}
}

void	quick_b(t_inform *inform, int size)
{
	int	i;
	int	cnt_push;

	cnt_push = 0;
	i = 0;
	if (quick_sort_end(inform, size))
		return ;
	partition(inform, size, &cnt_push);
	quick_b(inform, size - cnt_push);
	quick_a(inform, cnt_push);
	i = 0;
	while (i++ < cnt_push)
		pb(inform);
}
