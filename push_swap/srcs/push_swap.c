/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:05 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/06 14:55:26 by minskim2         ###   ########.fr       */
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
	if (is_sorted(inform->stack_a, inform->size_a))
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

int	main(int argc, char *argv[])
{
	t_inform	inform;

	if (argc < 2)
		return (0);
	init_stack(&inform, argc, argv);
	if (inform.size_a > 100)
		quick_a(&inform, inform.size_a);
	else
		sort_start(&inform);
	return (0);
}
