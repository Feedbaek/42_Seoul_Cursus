/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:51:17 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/06 14:52:12 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	run_instruction_1(t_inform *inform, t_predict *predict)
{
	int	i;

	i = 0;
	if (predict->cnt_a < predict->cnt_b)
	{
		while (i < predict->cnt_a)
		{
			rr(inform);
			i++;
		}
		while (i++ < predict->cnt_sum)
			rb(inform);
	}
	else
	{
		while (i < predict->cnt_b)
		{
			rr(inform);
			i++;
		}
		while (i++ < predict->cnt_sum)
			ra(inform);
	}
}

static	void	run_instruction_2(t_inform *inform, t_predict *predict)
{
	int	i;

	i = 0;
	if (predict->cnt_a < predict->cnt_b)
	{
		while (i < predict->cnt_a)
		{
			rrr(inform);
			i++;
		}
		while (i++ < predict->cnt_sum)
			rrb(inform);
	}
	else
	{
		while (i < predict->cnt_b)
		{
			rrr(inform);
			i++;
		}
		while (i++ < predict->cnt_sum)
			rra(inform);
	}
}

void	run_instruction(t_inform *inform, t_predict *predict)
{
	int	i;

	i = 0;
	if (predict->ra == 0 && predict->rb == 0)
		run_instruction_1(inform, predict);
	else if (predict->ra == 1 && predict->rb == 1)
		run_instruction_2(inform, predict);
	else if (predict->ra == 0)
	{
		while (i++ < predict->cnt_a)
			ra(inform);
		i = 0;
		while (i++ < predict->cnt_b)
			rrb(inform);
	}
	else
	{
		while (i++ < predict->cnt_a)
			rra(inform);
		i = 0;
		while (i++ < predict->cnt_b)
			rb(inform);
	}
	pa(inform);
}
