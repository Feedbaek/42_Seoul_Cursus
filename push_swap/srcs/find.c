/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:49:53 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/06 14:54:41 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_predict(t_predict *predict)
{
	predict->cnt_a = 0;
	predict->cnt_b = 0;
	predict->cnt_sum = 0;
	predict->ra = 0;
	predict->rb = 0;
}

int	find_max(int *stack, int size, int *idx)
{
	int	max;
	int	i;

	max = stack[0];
	*idx = 1;
	i = 0;
	while (i < size)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			*idx = (i + 1) % size;
		}
		i++;
	}
	return (max);
}

int	find_min(int *stack, int size, int *idx)
{
	int	min;
	int	i;

	min = stack[0];
	i = 0;
	while (i < size)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			*idx = i;
		}
		i++;
	}
	return (min);
}

void	find_index(t_inform *inform, int *i, int *j)
{
	int	limit;

	limit = find_max(inform->stack_a, inform->size_a, j);
	if (inform->stack_b[*i] > limit)
		return ;
	*j = 0;
	limit = find_min(inform->stack_a, inform->size_a, j);
	if (inform->stack_b[*i] < limit)
		return ;
	*j = 0;
	while (*j < inform->size_a)
	{
		if (inform->stack_a[(*j - 1 + inform->size_a) % inform->size_a]
			< inform->stack_b[*i] && (inform->stack_a[*j]
				> inform->stack_b[*i]))
		{
			return ;
		}
		(*j)++;
	}
}

void	find_instruction(t_inform *inform, t_predict *predict)
{
	int			i;
	int			j;
	t_predict	tmp;

	i = 0;
	while (i < inform->size_b)
	{
		init_predict(&tmp);
		j = 0;
		find_index(inform, &i, &j);
		cnt_instruction(inform, &tmp, i, j);
		if (tmp.cnt_sum < predict->cnt_sum)
		{
			*predict = tmp;
		}
		i++;
	}
}
