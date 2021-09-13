/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_section.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:48:29 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 20:05:04 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_sorted(int *stack, int n, int opt)
{
	int	i;

	i = 0;
	if (opt == 0)
		while (i < n - 1)
		{
			if (stack[i] > stack[i + 1])
				return (0);
			i++;
		}
	else
		while (i < n - 1)
		{
			if (stack[i] < stack[i + 1])
				return (0);
			i++;
		}
	return (1);
}

int	sorted_num(int *stack, int i, int size)
{
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (i);
		i++;
	}
	return (size - 1);
}

void	sort_3(t_inform *inform)
{
	if (is_sorted(inform->stack_a, inform->size_a, 0))
		return ;
	if (inform->stack_a[0] > inform->stack_a[2])
		ra(inform);
	else
		sa(inform);
}

void	sort_5(t_inform *inform, int len)
{
	if (len < 3)
	{
		pb(inform);
		pb(inform);
		sort_3(inform);
	}
	else
		push_to_b(inform, 5 - len);
	push_to_a(inform);
}

void	sort_2_3(t_inform *inform)
{
	int	size;
	int	*stack;

	stack = inform->stack_a;
	size = inform->size_a;
	if (size == 2 && stack[0] > stack[1])
		sa(inform);
	else if (size == 3)
		sort_3(inform);
}