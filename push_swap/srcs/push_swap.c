/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:05 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/30 20:09:07 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>
// 테스트용
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
	printf("stack_b: ");
	i = 0;
	while (i < inform->size_b)
	{
		printf("%d ", inform->stack_b[i]);
		i++;
	}
	printf("\n");
}

static	int	is_sorted(int *stack, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static	int	sorted_num(int *stack, int i, int size)
{
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (i);
		i++;
	}
	return (i);
}

void	move_section(t_inform *inform, int idx)
{
	if (idx + 1 > inform->size_a / 2)
		while (idx < inform->size_a - 1)
		{
			rra(inform);
			idx++;
		}
	else
		while (idx >= 0)
		{
			ra(inform);
			idx--;
		}
}

void	push_to_b(t_inform *inform, int len)
{
	int	i;
	int	size;

	i = 0;
	size = inform->size_a;
	while (i < size - len)
	{
		pb(inform);
		i++;
	}
}

int	find_long_section(t_inform *inform)
{
	int	i;
	int	j;
	int	idx;
	int	len;

	i = 0;
	len = 0;
	while (i < inform->size_a)
	{
		j = sorted_num(inform->stack_a, i, inform->size_a);
		if (j - i > len)
		{
			len = j - i + 1;
			idx = j;
		}
		i = j;
		i++;
	}
	move_section(inform, idx);
	return (len);
}

static	void	sort_3(t_inform *inform)
{
	if (!inform)
		return ;
}

static	void	sort_2_3_5(t_inform *inform)
{
	int	size;
	int	*stack;

	stack = inform->stack_a;
	size = inform->size_a;
	if (size == 2 && stack[0] > stack[1])
		sa(inform);
	else if (size == 3)
		sort_3(inform);
}

void	sort_start(t_inform *inform)
{
	int	len;

	len = find_long_section(inform);
	if (is_sorted(inform->stack_a, inform->size_a))
		return ;
	if (inform->size_a == 2 || inform->size_a == 3 || inform->size_a == 5)
		return (sort_2_3_5(inform));
	push_to_b(inform, len);
}

int	main(int argc, char *argv[])
{
	t_inform	inform;

	if (argc < 2)
		return (0);
	init_stack(&inform, argc, argv);
	//test(&inform);
	//real_quick_sort(inform.stack_a, 0, inform.size_a - 1);
	test(&inform);
	sort_start(&inform);
	//quick_a(&inform, inform.size_a);
	test(&inform);
	return (0);
}
