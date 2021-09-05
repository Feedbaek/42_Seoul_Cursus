/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:05 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/05 17:12:44 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
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

void	init_predict(t_predict *predict)
{
	predict->cnt_a = 0;
	predict->cnt_b = 0;
	predict->cnt_sum = 0;
	predict->ra = 0;
	predict->rb = 0;
}

void	cnt_instruction(t_inform *inform, t_predict *predict, int i, int j)
{
	int	cnt;

	predict->cnt_a = j;
	predict->cnt_b = i;
	if (j > i)
		predict->cnt_sum = j;
	else
		predict->cnt_sum = i;
	cnt = j + inform->size_b - i;
	if (cnt < predict->cnt_sum)
	{
		predict->cnt_b = inform->size_b - i;
		predict->rb = 1;
		predict->cnt_sum = cnt;
	}
	cnt = inform->size_a - j + i;
	if (cnt < predict->cnt_sum)
	{
		predict->cnt_a = inform->size_a - j;
		predict->cnt_b = i;
		predict->ra = 1;
		predict->rb = 0;
		predict->cnt_sum = cnt;
	}
	if (inform->size_a - j > inform->size_b - i)
		cnt = inform->size_a - j;
	else
		cnt = inform->size_b - i;
	if(cnt < predict->cnt_sum)
	{
		predict->cnt_b = inform->size_b - i;
		predict->rb = 1;
		predict->cnt_sum = cnt;
	}
}

int	find_max(int *stack, int size, int *idx)
{
	int	max;
	int	i;

	max = stack[0];
	i = 0;
	while (i < size)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			*idx = i + 1;
		}
		i++;
	}
	return (max);
}

int	find_min(int *stack, int size, int *idx)
{
	int	min;
	int	i;

	min = stack[0];
	i = 0;
	while (i < size)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			*idx = i;
		}
		i++;
	}
	printf("min: %d\n", min);
	return (min);
}

void	find_index(t_inform *inform, int *i, int *j)
{
	int	limit;
	// 최댓값인지 체크
	limit = find_max(inform->stack_a, inform->size_a, j);
	if (inform->stack_b[*i] > limit)
		return ;
	// 최솟값인지 체크
	*j = 0;
	limit = find_min(inform->stack_a, inform->size_a, j);
	if (inform->stack_b[*i] < limit)
		return ;
	// 이전 인덱스보다 크고 다음 인덱스보다 작은 위치 찾기
	// -> 인덱스가 0이거나 size-1인 경우 생각하기
	*j = 0;
	while (*j < inform->size_a)
	{
		if (inform->stack_a[(*j - 1 + inform->size_a) % inform->size_a] < inform->stack_b[*i] &&
			(inform->stack_a[*j] > inform->stack_b[*i]))
		{
			return ;
		}
		(*j)++;
	}
	error_push_swap("Except\n");
}

void	find_instruction(t_inform *inform, t_predict *predict)
{
	int			i;
	int			j;
	t_predict	tmp;

	i = 0;
	while (i < inform->size_b)
	{
		init_predict(&tmp);
		tmp.cnt_sum = inform->size_a + inform->size_b;
		j = 0;
		find_index(inform, &i, &j);
		cnt_instruction(inform, &tmp, i, j);
		//while (j < inform->size_a)	// 최대값인 경우, 최소값인 경우, 사이값인 경우 나눠서 찾기
		//{

		//	if (inform->stack_b[i] < inform->stack_a[j])
		//	{
		//		if ((i == 0 && inform->stack_b[i] > inform->stack_a[inform->size_a - 1]) || i > 0)
		//		{
		//			cnt_instruction(inform, &tmp, i, j);
		//			break ;
		//		}
		//	}
		//	j++;
		//}
		if (tmp.cnt_sum < predict->cnt_sum)
			*predict = tmp;
		i++;
	}
}

void	run_instruction(t_inform *inform, t_predict *predict)
{
	int	i;

	i = 0;
	if (predict->ra == 0 && predict->rb == 0)
	{
		if (predict->cnt_a < predict->cnt_b)
		{
			while (i < predict->cnt_a)
			{
				rr(inform);
				i++;
			}
			while (i++ < predict->cnt_sum)
				rb(inform);
		}
		else
		{
			while (i < predict->cnt_b)
			{
				rr(inform);
				i++;
			}
			while (i++ < predict->cnt_sum)
				ra(inform);
		}
	}
	else if (predict->ra == 1 && predict->rb == 1)
	{
		if (predict->cnt_a < predict->cnt_b)
		{
			while (i < predict->cnt_a)
			{
				rrr(inform);
				i++;
			}
			while (i++ < predict->cnt_sum)
				rrb(inform);
		}
		else
		{
			while (i < predict->cnt_b)
			{
				rrr(inform);
				i++;
			}
			while (i++ < predict->cnt_sum)
				rra(inform);
		}
	}
	else if (predict->ra == 0)
	{
		while (i++ < predict->cnt_a)
			ra(inform);
		i = 0;
		while (i++ < predict->cnt_b)
			rrb(inform);
	}
	else
	{
		while (i++ < predict->cnt_a)
			rra(inform);
		i = 0;
		while (i++ < predict->cnt_b)
			rb(inform);
	}
	pa(inform);
}

void	push_to_a(t_inform *inform)
{
	t_predict	predict;

	while (inform->size_b != 0)
	{
		init_predict(&predict);
		predict.cnt_sum = inform->size_a + inform->size_b;
		find_instruction(inform, &predict);
		run_instruction(inform, &predict);
	}
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

	i = 0;
	while (i < len)
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
	len = -1;
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
	if (len == 1)
		len = 2;
	return (len);
}

void	sort_end(t_inform *inform)
{
	int	idx;

	idx = 0;
	find_min(inform->stack_a, inform->size_a, &idx);
	if (idx > inform->size_a / 2)
		while (idx < inform->size_a)
		{
			rra(inform);
			idx++;
		}
	else
		while (idx > 0)
		{
			ra(inform);
			idx--;
		}
}

void	sort_start(t_inform *inform)
{
	int	len;

	len = find_long_section(inform);
	test(inform);
	if (is_sorted(inform->stack_a, inform->size_a))
		return ;
	if (inform->size_a == 2 || inform->size_a == 3)
	{
		sort_2_3(inform);
		return (sort_end(inform));
	}
	if (inform->size_a == 5)
	{
		sort_5(inform, len);
		return (sort_end(inform));
	}
	push_to_b(inform, inform->size_a - len);
	push_to_a(inform);
	sort_end(inform);
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
