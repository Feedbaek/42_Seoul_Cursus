/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:59:26 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/25 20:50:56 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	*new_stack(int size)
{
	int	*new_stack;

	new_stack = (int *)malloc(sizeof(int) * size);
	if (!new_stack)
		error_push_swap("Error\n");
	return (new_stack);
}

void	pa(t_inform *inform)
{
	int	size;
	int	*new_stack_a;
	int	*new_stack_b;

	if (!inform->size_b)
		return ;
	size = ++inform->size_a;
	new_stack_a = new_stack(size);
	new_stack_a[0] = inform->stack_b[0];
	if (inform->stack_a != 0)
	{
		ft_memcpy(&new_stack_a[1], inform->stack_a, sizeof(int) * (size - 1));
		free(inform->stack_a);
	}
	inform->stack_a = new_stack_a;
	size = --inform->size_b;
	new_stack_b = 0;
	if (size != 0)
	{
		new_stack_b = new_stack(size);
		ft_memcpy(new_stack_b, &inform->stack_b[1], sizeof(int) * size);
	}
	free(inform->stack_b);
	inform->stack_b = new_stack_b;
	ft_putstr("pa\n");
	test(inform);
}

void	pb(t_inform *inform)
{
	int	size;
	int	*new_stack_a;
	int	*new_stack_b;

	if (!inform->size_a)
		return ;
	size = ++inform->size_b;
	new_stack_b = new_stack(size);
	new_stack_b[0] = inform->stack_a[0];
	if (inform->stack_b != 0)
	{
		ft_memcpy(&new_stack_b[1], inform->stack_b, sizeof(int) * (size - 1));
		free(inform->stack_b);
	}
	inform->stack_b = new_stack_b;
	size = --inform->size_a;
	new_stack_a = 0;
	if (size != 0)
	{
		new_stack_a = new_stack(size);
		ft_memcpy(new_stack_a, &inform->stack_a[1], sizeof(int) * size);
	}
	free(inform->stack_a);
	inform->stack_a = new_stack_a;
	ft_putstr("pb\n");
	test(inform);
}
