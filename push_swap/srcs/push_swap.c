/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:05 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/29 01:08:33 by minskim2         ###   ########.fr       */
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

int	sort_end(t_inform *inform, int size)
{
	if (is_sorted(inform->stack_a, size) || size < 2)
		return (1);
	if (size == 2)
	{
		sort_2(inform);
		return (1);
	}
	if (size == 3)
	{
		sort_3(inform);
		return (1);
	}
	return (0);
}

void	quick_sort_size_big(t_inform *inform, int *cnt_push, int pivot)
{
	while (*(inform->stack_a) != pivot)
	{
		if (*(inform->stack_a) < pivot)
		{
			pb(inform);
			(*cnt_push)++;
		}
		else
			ra(inform);
	}
}

void	quick_sort_size_small(t_inform *inform, int size, int *cnt_push, int pivot)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (*(inform->stack_a) < pivot)
		{
			pb(inform);
			(*cnt_push)++;
		}
		else
			ra(inform);
		i++;
	}
	i = 0;
	while (i < size - *cnt_push + 1)
	{
		rra(inform);
		i++;
	}
}

void	quick_sort(t_inform *inform, int size, int *cnt_push)
{
	int	pivot;

	pivot = *(inform->stack_a);
	ra(inform);
	if (size > (inform->size_a / 2))
		quick_sort_size_big(inform, cnt_push, pivot);
	else
		quick_sort_size_small(inform, size, cnt_push, pivot);
}

void	quick_a(t_inform *inform, int size)
{
	int	pivot;
	int	i;
	int	cnt_push;

	cnt_push = 0;
	if (sort_end(inform, size))
		return ;
	pivot = *(inform->stack_a);
	quick_sort(inform, size, &cnt_push);
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

// 만약 pivot 작업을 하는 구간이 정/역으로 정렬되어 있으면 pivot을 나눌 필요가 없음.
// 전처리를 이용한 정렬 최적화
//전처리를 하는 방법은 여러가지가 있겠지만 가장 대표적인 케이스는 역으로 정렬되어 있을 때다. 이 경우엔 quick sort는 최악의 정렬속도가 나오는데 단순히 원소 순서만 정방향으로 바꾼다면 quick sort를 할 필요가 없어진다.
//전처리 케이스를 추가하여 정렬 속도를 줄인다.
// 현재는 명령어들을 모두 즉시 표준출력에 출력하도록 되어 있다. 이 명령어들은 "압축"을 시킬 수 있다
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
