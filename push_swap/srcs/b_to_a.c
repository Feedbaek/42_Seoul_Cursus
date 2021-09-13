/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:06:26 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 19:45:43 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	b_to_a_while(t_inform *inform, t_param *param)
{
	if (inform->stack_b[0] <= param->small_pivot)
	{
		if (param->check_rr)
		{
			rr(inform);
			param->check_rr = 0;
		}
		else
			rb(inform);
		param->cnt_rb++;
	}
	else
	{
		if (param->check_rr)
			ra(inform);
		param->check_rr = 0;
		pa(inform);
		param->cnt_pa++;
		if (inform->stack_a[0] < param->big_pivot)
		{
			param->check_rr = 1;
			param->cnt_ra++;
		}
	}
}

void	b_to_a(t_inform *inform, int size)
{
	t_param	param;

	if (set_b_to_a(inform, &param, size))
		return ;
	while (0 < size--)
	{
		if (b_to_a_check_pivot(inform, param.small_pivot, size + 1))
		{
			param.cnt_skip = size + 1;
			break ;
		}
		b_to_a_while(inform, &param);
	}
	if (param.check_rr)
		ra(inform);
	a_to_b(inform, param.cnt_pa - param.cnt_ra);
	b_to_a_call_rrr(inform, param.cnt_ra, param.cnt_rb);
	a_to_b(inform, param.cnt_ra);
	b_to_a(inform, param.cnt_rb + param.cnt_skip);
}
