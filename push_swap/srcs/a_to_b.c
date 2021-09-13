/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:17:50 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 18:48:16 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	a_to_b_while(t_inform *inform, t_param *param)
{
	if (inform->stack_a[0] >= param->big_pivot)
	{
		if (param->check_rr)
		{
			rr(inform);
			param->check_rr = 0;
		}
		else
			ra(inform);
		param->cnt_ra++;
	}
	else
	{
		if (param->check_rr)
			rb(inform);
		param->check_rr = 0;
		pb(inform);
		param->cnt_pb++;
		if (inform->stack_b[0] >= param->small_pivot)
		{
			param->check_rr = 1;
			param->cnt_rb++;
		}
	}
}

void	first_a_to_b_while(t_inform *inform, t_param *param)
{
	if (inform->stack_a[0] >= param->big_pivot)
	{
		if (param->check_rr)
		{
			rr(inform);
			param->check_rr = 0;
		}
		else
			ra(inform);
		param->cnt_ra++;
	}
	else
	{
		if (param->check_rr)
			rb(inform);
		param->check_rr = 0;
		pb(inform);
		param->cnt_pb++;
		if (inform->stack_b[0] < param->small_pivot)
		{
			param->check_rr = 1;
			param->cnt_rb++;
		}
	}
}

void	a_to_b(t_inform *inform, int size)
{
	t_param	param;

	if (set_a_to_b(inform, &param, size))
		return ;
	while (0 < size--)
	{
		if (a_to_b_check_pivot(inform, param.big_pivot, size + 1))
		{
			param.cnt_skip = size + 1;
			break ;
		}
		a_to_b_while(inform, &param);
	}
	if (param.check_rr)
		rb(inform);
	a_to_b_call_rrr(inform, param.cnt_ra, param.cnt_rb);
	a_to_b(inform, param.cnt_ra + param.cnt_skip);
	b_to_a(inform, param.cnt_rb);
	b_to_a(inform, param.cnt_pb - param.cnt_rb);
}

void	first_a_to_b(t_inform *inform, int size)
{
	t_param	param;

	if (set_a_to_b(inform, &param, size))
		return ;
	while (0 < size--)
	{
		if (a_to_b_check_pivot(inform, param.big_pivot, size + 1))
		{
			param.cnt_skip = size + 1;
			break ;
		}
		first_a_to_b_while(inform, &param);
	}
	if (param.check_rr)
		rb(inform);
	a_to_b(inform, param.cnt_ra + param.cnt_skip);
	b_to_a(inform, param.cnt_pb - param.cnt_rb);
	b_to_a(inform, param.cnt_rb);
}
