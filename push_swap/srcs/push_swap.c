/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:31:12 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 20:50:34 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	test(t_inform *inform)
{
	int	i;

	i = 0;
	printf("stack_a: ");
	while (i < inform->size_a)
	{
		printf("%d ", inform->stack_a[i]);
		i++;
	}
	i = 0;
	printf("\nstack_b: ");
	while (i < inform->size_b)
	{
		printf("%d ", inform->stack_b[i]);
		i++;
	}
	printf("\n");
}

int	is_sorted(int *stack, int n, int opt)
{
	int	i;

	i = 0;
	if (opt == 0)
		while (i < n - 1)
		{
			if (stack[i] > stack[i + 1])
				return (0);
			i++;
		}
	else
		while (i < n - 1)
		{
			if (stack[i] < stack[i + 1])
				return (0);
			i++;
		}
	return (1);
}

static	void	main_sort_3(t_inform *inform)
{
	if (is_sorted(inform->stack_a, 3, 0))
		return ;
	if (inform->stack_a[0] < inform->stack_a[1])
	{
		rra(inform);
		if (inform->stack_a[0] > inform->stack_a[1])
			sa(inform);
	}
	else if (inform->stack_a[1] < inform->stack_a[2] && inform->stack_a[2] < inform->stack_a[0])
		ra(inform);
	else
	{
		sa(inform);
		if (inform->stack_a[1] > inform->stack_a[2])
			rra(inform);
	}
}

static	void	main_sort_5(t_inform *inform)
{
	int	pivot;
	int	i;

	pivot = find_pivot(inform->stack_a, 5);
	i = 0;
	while (i < 5)
	{
		if (inform->stack_a[0] <= pivot)
			pb(inform);
		else
			ra(inform);
		i++;
	}
	main_sort_3(inform);
	pa(inform);
	pa(inform);
	if (inform->stack_a[0] > inform->stack_a[1])
		sa(inform);
}

int	main(int argc, char *argv[])
{
	t_inform	inform;

	if (argc < 2)
		return (0);
	init_stack(&inform, argc, argv);
	if (is_sorted(inform.stack_a, inform.size_a, 0))
		return (0);
	if (inform.size_a == 5)
		main_sort_5(&inform);
	else if (inform.size_a == 3)
		main_sort_3(&inform);
	else if (inform.size_a == 2)
	{
		if (inform.stack_a[0] > inform.stack_a[1])
			sa(&inform);
	}
	else
		first_a_to_b(&inform, inform.size_a);
	exit(0);
}
