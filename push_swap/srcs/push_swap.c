/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:05 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/25 00:10:55 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	valid_check(t_inform *inform, int value, int n)
{
	int	idx;

	if (!value)
		error_push_swap("Error\n");
	idx = 0;
	while (idx < n)
	{
		if (inform->stack_a[idx] == value)
			error_push_swap("Error\n");
		idx++;
	}
}

void	init_stack(t_inform *inform, int argc, char *argv[])
{
	int	idx;
	int	value;

	inform->stack_b = (int *)malloc(sizeof(int) * 1);
	inform->stack_a = (int *)malloc(sizeof(int) * argc);
	if (!inform->stack_a || !inform->stack_b)
		error_push_swap("Error\n");
	inform->size_a = argc - 1;
	idx = 0;
	while (idx < inform->size_a)
	{
		value = ft_atoi(argv[idx + 1]);
		valid_check(inform, value, idx);
		inform->stack_a[idx] = value;
		idx++;
	}
	inform->stack_a[inform->size_a] = 0;
	inform->size_b = 0;
	inform->stack_b[0] = 0;
}

void	test(t_inform *inform)
{
	for (int i=0; i<inform->size_a; i++)
		printf("%d ", inform->stack_a[i]);
}

int	main(int argc, char *argv[])
{
	t_inform	inform;

	if (argc < 2)
		return (0);
	init_stack(&inform, argc, argv);
	test(&inform);
	return (0);
}
