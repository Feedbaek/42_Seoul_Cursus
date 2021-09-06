/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:53:07 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/06 14:54:56 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	move_section(t_inform *inform, int idx)
{
	if (idx + 1 > inform->size_a / 2)
	{
		while (idx < inform->size_a - 1)
		{
			rra(inform);
			idx++;
		}
	}
	else
	{
		while (idx >= 0)
		{
			ra(inform);
			idx--;
		}
	}
}

int	cnt_sorted_len(t_inform *inform)
{
	int	len;
	int	i;

	i = 0;
	len = 1;
	while (i < inform->size_a - 1)
	{
		if (inform->stack_a[i] < inform->stack_a[i + 1])
			len++;
		else
			len = 1;
		i++;
	}
	return (len);
}

int	find_long_section(t_inform *inform)
{
	int	i;
	int	j;
	int	idx;
	int	len;

	i = 0;
	len = 0;
	while (i < inform->size_a - 1)
	{
		j = sorted_num(inform->stack_a, i, inform->size_a);
		if (j - i + 1 > len)
		{
			len = j - i + 1;
			idx = j;
		}
		i = j;
		i++;
	}
	move_section(inform, idx);
	len = cnt_sorted_len(inform);
	return (len);
}
