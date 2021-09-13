/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:55:11 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 20:30:09 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_to_a(t_inform *inform)
{
	t_predict	predict;

	while (inform->size_b != 0)
	{
		init_predict(&predict);
		predict.cnt_sum = inform->size_a + inform->size_b;
		find_instruction(inform, &predict);
		run_instruction(inform, &predict);
	}
}

void	push_to_b(t_inform *inform, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		pb(inform);
		i++;
	}
}

void	sort_end(t_inform *inform)
{
	int	idx;

	idx = 0;
	find_min(inform->stack_a, inform->size_a, &idx);
	if (idx > inform->size_a / 2)
	{
		while (idx < inform->size_a)
		{
			rra(inform);
			idx++;
		}
	}
	else
	{
		while (idx > 0)
		{
			ra(inform);
			idx--;
		}
	}
}

void	sort_start(t_inform *inform)
{
	int	len;

	len = find_long_section(inform);
	if (is_sorted(inform->stack_a, inform->size_a, 0))
		return ;
	if (inform->size_a == 2 || inform->size_a == 3)
	{
		sort_2_3(inform);
		return (sort_end(inform));
	}
	if (inform->size_a == 5)
	{
		sort_5(inform, len);
		return (sort_end(inform));
	}
	push_to_b(inform, inform->size_a - len);
	push_to_a(inform);
	sort_end(inform);
}
