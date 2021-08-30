/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:05 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/30 17:55:07 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	int	is_sorted(int *stack, int n)
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

static	void	sort_2(t_inform *inform)
{
	if (inform->stack_b[0] < inform->stack_b[1])
		sb(inform);
}

	// 3 1 2	ra 12-3 sa 21-3 rra 321
	// 2 1 3	ra 13-2 sa 31-2 rra 231 sa 321

	// 2 3 1	sa 321
	// 1 3 2	sa 312 ra 12-3 sa 21-3 rra 321
	// 1 2 3	sa 213 ra 13-2 sa 31-2 rra 231 sa 321

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

static	int	sort_end(t_inform *inform, int size)
{
	if (is_sorted(inform->stack_b, size) || size < 2)
		return (1);
	if (size == 2)
	{
		sort_2(inform);
		return (1);
	}
	if (size == 3)
	{
		sort_3(inform);
		return (1);
	}
	return (0);
}

static	void	quick_sort_size_big(t_inform *inform, int *cnt_push, int pivot)
{
	while (*(inform->stack_b) != pivot)
	{
		if (*(inform->stack_b) > pivot)
		{
			pa(inform);
			(*cnt_push)++;
		}
		else
			rb(inform);
	}
}

static	void	quick_sort_size_small(t_inform *inform, int size, int *cnt_push, int pivot)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (*(inform->stack_b) > pivot)
		{
			pa(inform);
			(*cnt_push)++;
		}
		else
			rb(inform);
		i++;
	}
	i = 0;
	while (i < size - *cnt_push + 1)
	{
		rrb(inform);
		i++;
	}
}

static	void	quick_sort(t_inform *inform, int size, int *cnt_push)
{
	int	pivot;

	pivot = *(inform->stack_b);
	rb(inform);
	if (size > (inform->size_b / 2))
		quick_sort_size_big(inform, cnt_push, pivot);
	else
		quick_sort_size_small(inform, size, cnt_push, pivot);
}

void	quick_b(t_inform *inform, int size)
{
	int	i;
	int	cnt_push;

	cnt_push = 0;
	i = 0;
	if (sort_end(inform, size))
		return ;
	quick_sort(inform, size, &cnt_push);
	if (!is_sorted(inform->stack_b, size - cnt_push))
	{
		pa(inform);
		cnt_push++;
		quick_b(inform, size - cnt_push);
	}
	i = 0;
	quick_a(inform, cnt_push);
	while (i < cnt_push)
	{
		pb(inform);
		i++;
	}
}
