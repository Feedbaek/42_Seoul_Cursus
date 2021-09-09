/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:09:52 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/09 19:40:49 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	int	is_sorted_a(int *stack, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static	void	sort_3(t_inform *inform)
{
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

static	int	quick_sort_end(t_inform *inform, int size)
{
	if (is_sorted_a(inform->stack_a, size) || size < 2)
		return (1);
	if (size == 2 && inform->stack_a[0] > inform->stack_a[1])
	{
		sa(inform);
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

	pivot = find_pivot(inform->stack_a, size);
	i = 0;
	while (i < size)
	{
		if (inform->stack_a[0] < pivot)
		{
			pb(inform);
			(*cnt_push)++;
		}
		else
			ra(inform);
		i++;
	}
	i = 0;
	while (i < size - *cnt_push)
	{
		rra(inform);
		i++;
	}
}

void	quick_a(t_inform *inform, int size)
{
	int	i;
	int	cnt_push;

	cnt_push = 0;
	i = 0;
	if (quick_sort_end(inform, size))
		return ;
	partition(inform, size, &cnt_push);
	quick_a(inform, size - cnt_push);
	quick_b(inform, cnt_push);
	i = 0;
	while (i++ < cnt_push)
		pa(inform);
}

// quick_b도 만들기,
