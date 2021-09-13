/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnt_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:47:17 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 20:29:54 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	cnt_instruction_1(t_inform *inform,
	t_predict *predict, int i, int j)
{
	int	cnt;

	predict->cnt_a = j;
	predict->cnt_b = i;
	if (j > i)
		predict->cnt_sum = j;
	else
		predict->cnt_sum = i;
	cnt = j + inform->size_b - i;
	if (cnt < predict->cnt_sum)
	{
		predict->cnt_b = inform->size_b - i;
		predict->rb = 1;
		predict->cnt_sum = cnt;
	}
}

static	void	cnt_instruction_2(t_inform *inform,
	t_predict *predict, int i, int j)
{
	int	cnt;

	cnt = inform->size_a - j + i;
	if (cnt < predict->cnt_sum)
	{
		predict->cnt_a = inform->size_a - j;
		predict->cnt_b = i;
		predict->ra = 1;
		predict->rb = 0;
		predict->cnt_sum = cnt;
	}
	if (inform->size_a - j > inform->size_b - i)
		cnt = inform->size_a - j;
	else
		cnt = inform->size_b - i;
	if (cnt < predict->cnt_sum)
	{
		predict->cnt_b = inform->size_b - i;
		predict->rb = 1;
		predict->cnt_sum = cnt;
	}
}

void	cnt_instruction(t_inform *inform, t_predict *predict, int i, int j)
{
	cnt_instruction_1(inform, predict, i, j);
	cnt_instruction_2(inform, predict, i, j);
}
