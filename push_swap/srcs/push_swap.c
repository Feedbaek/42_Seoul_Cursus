/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:05 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/28 21:15:12 by minskim2         ###   ########.fr       */
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

int	is_sorted(int *stack, int n)
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

void	sort_2(t_inform *inform)
{
	if (inform->stack_a[0] > inform->stack_a[1])
		sa(inform);
}

	// 2 3 1	ra 31-2 sa 13-2 rra 213 sa 123
	// 1 3 2	ra 32-1 sa 23-1 rra 123

	// 2 1 3	sa 123
	// 3 1 2	sa 132 ra 32-1 sa 23-1 rra 123
	// 3 2 1	sa 231 ra 31-2 sa 13-2 rra 213 sa 123

void	sort_3(t_inform *inform)
{
	if (inform->stack_a[0] < inform->stack_a[1])
	{
		ra(inform);
		sa(inform);
		rra(inform);
		if (inform->stack_a[0] > inform->stack_a[1])
			sa(inform);
	}
	else
	{
		sa(inform);
		if (inform->stack_a[1] > inform->stack_a[2])
		{
			ra(inform);
			sa(inform);
			rra(inform);
			if (inform->stack_a[0] > inform->stack_a[1])
				sa(inform);
		}
	}
}

void	quick_a(t_inform *inform, int size)
{
	int	pivot;
	int	i;
	int	cnt_push;

	cnt_push = 0;
	if (is_sorted(inform->stack_a, size) || size < 2)
		return ;
	if (size == 2)
		return (sort_2(inform));
	if (size == 3)
		return (sort_3(inform));
	pivot = *(inform->stack_a);
	ra(inform);
	if (size > (inform->size_a / 2))
	{
		while (*(inform->stack_a) != pivot)
		{
			if (*(inform->stack_a) < pivot)
			{
				pb(inform);
				cnt_push++;
			}
			else
				ra(inform);
		}
	}
	else
	{
		i = 0;
		while (i < size)
		{
			if (*(inform->stack_a) < pivot)
			{
				pb(inform);
				cnt_push++;
			}
			else
				ra(inform);
			i++;
		}
		i = 0;
		while (i < size - cnt_push + 1)
		{
			rra(inform);
			i++;
		}
	}
	if (!is_sorted(inform->stack_a, size - cnt_push))
	{
		pb(inform);
		cnt_push++;
		quick_a(inform, size - cnt_push);
	}
	i = 0;
	while (i < cnt_push)
	{
		pa(inform);
		i++;
	}
	quick_a(inform, cnt_push);
}

void	quick(t_inform *inform)
{
	quick_a(inform, inform->size_a);
}

int	main(int argc, char *argv[])
{
	t_inform	inform;

	if (argc < 2)
		return (0);
	init_stack(&inform, argc, argv);
	quick(&inform);
	//test(&inform);
	return (0);
}
