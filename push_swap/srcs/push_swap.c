/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:05 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/26 13:42:43 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>
// 테스트용
void	test(t_inform *inform)
{
	(void)inform;
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

int		is_sorted(int *stack, int n)
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

void	quick_a(t_inform *inform, int size)
{
	int	pivot;
	int	i;
	int	cnt_push;

	cnt_push = 0;
	if (is_sorted(inform->stack_a, size) || size < 2)
		return ;
	pivot = *(inform->stack_a);
	ra(inform);
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
	if (!is_sorted(inform->stack_a, size - cnt_push))
	{
		ra(inform);
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

int	main(int argc, char *argv[])
{
	t_inform	inform;

	if (argc < 2)
		return (0);
	init_stack(&inform, argc, argv);
	quick_a(&inform, inform.size_a);
	test(&inform);
	return (0);
}
