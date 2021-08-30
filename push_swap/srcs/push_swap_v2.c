/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_v3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:05 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/29 17:40:38 by minskim2         ###   ########.fr       */
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

static	void	sort_2(t_inform *inform)
{
	if (inform->stack_a[0] > inform->stack_a[1])
		sa(inform);
}

static	void	sort_3(t_inform *inform)
{
	// 1 3 2	2 1 3 sa 123
	// 2 1 3	2 1 3 sa 123
	// 2 3 1	1 2 3
	// 3 1 2	3 1 2 ra 123

	// 3 2 1	ra 213 sa 123
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

static	int	sort_end(t_inform *inform, int size)
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

static	void	partition(t_inform *inform, int size, int *cnt_push)
{
	int	pivot;
	int	i;

	pivot = find_pivot(inform, size);
	i = 0;
	while (i++ < size)
	{
		if (inform->stack_a[0] < pivot)
		{
			pb(inform);
			(*cnt_push)++;
		}
		else
			ra(inform);
	}
	i = 0;
	while (i < size - *cnt_push)
	{
		rra(inform);
		i++;
	}
}

void	quick_a(t_inform *inform, int size)
{
	int	i;
	int	cnt_push;

	cnt_push = 0;
	i = 0;
	if (sort_end(inform, size))
		return ;
	partition(inform, size, &cnt_push);
	if (!is_sorted(inform->stack_a, size - cnt_push))
		quick_a(inform, size - cnt_push);
	i = 0;
	while (i++ < cnt_push)
		pa(inform);
	quick_a(inform, cnt_push);
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
	//test(&inform);
	//real_quick_sort(inform.stack_a, 0, inform.size_a - 1);
	quick_a(&inform, inform.size_a);
	//test(&inform);
	return (0);
}
