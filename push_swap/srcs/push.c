/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:59:26 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/24 18:57:02 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pa(t_inform *inform)
{
	int	tmp;
	int	size;
	int	*new_stack_a;
	int	*new_stack_b;

	if (!inform->stack_b[0])
		return ;
	tmp = inform->stack_b[0];
	size = inform->size_a++;
	new_stack_a = (int *)malloc(sizeof(int) * size + 1);
	ft_memcpy(new_stack_a, inform->stack_a, sizeof(int) * size);
	free(inform->stack_a);
	new_stack_a[size] = tmp;
	inform->stack_a = new_stack_a;
	size = inform->size_b--;
	new_stack_b = (int *)maloc(sizeof(int) * size - 1);
	ft_memcpy(new_stack_b, &inform->stack_b[1], sizeof(int) * (size - 1));
	free(inform->stack_b);
	inform->size_b = new_stack_b;
}
