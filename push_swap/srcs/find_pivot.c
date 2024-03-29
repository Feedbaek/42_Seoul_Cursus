/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 12:56:11 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/11 15:06:23 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	swap(int *stack, int left, int right)
{
	int	tmp;

	tmp = stack[left];
	stack[left] = stack[right];
	stack[right] = tmp;
}

static	int	partition(int *stack, int left, int right)
{
	int	pivot;
	int	low;
	int	high;

	pivot = stack[left];
	low = left + 1;
	high = right;
	while (low < high)
	{
		while (low <= right && stack[low] < pivot)
			low++;
		while (high >= left && stack[high] > pivot)
			high--;
		if (low < high)
			swap(stack, low, high);
	}
	swap(stack, left, high);
	return (high);
}

void	real_quick_sort(int *stack, int left, int right)
{
	int	q;

	if (left + 1 == right)
	{
		if (stack[left] > stack[right])
			swap(stack, left, right);
		return ;
	}
	if (left < right)
	{
		q = partition(stack, left, right);
		real_quick_sort(stack, left, q - 1);
		real_quick_sort(stack, q + 1, right);
	}
}

int	find_pivot(int *stack, int size)
{
	int	*copy;
	int	i;
	int	ret;

	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		error_push_swap("Error\n");
	i = 0;
	while (i < size)
	{
		copy[i] = stack[i];
		i++;
	}
	real_quick_sort(copy, 0, size - 1);
	ret = copy[size / 2 - 1];
	free(copy);
	return (ret);
}

void	find_pivot_2(int *stack, int size, int *big_pivot, int *small_pivot)
{
	int	*copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		error_push_swap("Error\n");
	i = 0;
	while (i < size)
	{
		copy[i] = stack[i];
		i++;
	}
	real_quick_sort(copy, 0, size - 1);
	*big_pivot = copy[2 * (size / 3) - 1];
	*small_pivot = copy[(size / 3) - 1];
	free(copy);
}
