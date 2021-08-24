/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:59:26 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/25 00:07:50 by minskim2         ###   ########.fr       */
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
	size = ++inform->size_a;
	new_stack_a = (int *)malloc(sizeof(int) * size + 1);
	if (!new_stack_a)
		error_push_swap("Error\n");
	ft_memcpy(new_stack_a, inform->stack_a, sizeof(int) * (size - 1));
	new_stack_a[size - 1] = tmp;
	new_stack_a[size] = 0;
	free(inform->stack_a);
	inform->stack_a = new_stack_a;
	size = --inform->size_b;
	new_stack_b = (int *)malloc(sizeof(int) * size + 1);
	if (!new_stack_b)
		error_push_swap("Error\n");
	ft_memcpy(new_stack_b, &inform->stack_b[1], sizeof(int) * size);
	free(inform->stack_b);
	inform->stack_b = new_stack_b;
	ft_putstr("pa\n");
}

void	pb(t_inform *inform)
{
	int	tmp;
	int	size;
	int	*new_stack_a;
	int	*new_stack_b;

	if (!inform->stack_a[0])
		return ;
	tmp = inform->stack_a[0];
	size = ++inform->size_b;
	new_stack_b = (int *)malloc(sizeof(int) * size + 1);
	if (!new_stack_b)
		error_push_swap("Error\n");
	ft_memcpy(new_stack_b, inform->stack_b, sizeof(int) * (size - 1));
	new_stack_b[size - 1] = tmp;
	new_stack_b[size] = 0;
	free(inform->stack_b);
	inform->stack_b = new_stack_b;
	size = --inform->size_a;
	new_stack_a = (int *)malloc(sizeof(int) * size + 1);
	if (!new_stack_a)
		error_push_swap("Error\n");
	ft_memcpy(new_stack_a, &inform->stack_a[1], sizeof(int) * size);
	free(inform->stack_a);
	inform->stack_a = new_stack_a;
	ft_putstr("pb\n");
}
