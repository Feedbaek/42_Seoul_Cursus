/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:05 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/25 16:01:45 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	valid_check(t_inform *inform, int value, int n)
{
	int	idx;

	idx = 0;
	while (idx < n)
	{
		if (inform->stack_a[idx] == value)
			error_push_swap("Error\n");
		idx++;
	}
}

void	split_argv(t_inform *inform, int argc, char *argv[])
{
	int		value;
	int		n;
	int		i;
	int		idx;
	char	**split;

	n = 1;
	idx = 0;
	while (n < argc)
	{
		split = ft_split(argv[n], ' ');
		if (!split)
			error_push_swap("Error\n");
		i = 0;
		while (split[i])
		{
			value = ft_atoi(split[i++]);
			valid_check(inform, value, idx);
			inform->stack_a[idx++] = value;
		}
		free(split);
		n++;
	}
}

void	init_stack(t_inform *inform, int argc, char *argv[])
{
	int	n;
	int	cnt;

	n = 1;
	cnt = 0;
	while (n < argc)
		cnt += cnt_word(argv[n++], ' ');
	inform->stack_a = (int *)malloc(sizeof(int) * cnt);
	if (!inform->stack_a)
		error_push_swap("Error\n");
	inform->size_a = cnt;
	split_argv(inform, argc, argv);
	inform->stack_b = 0;
	inform->size_b = 0;
}

void	test(t_inform *inform)
{
	for (int i = 0; i < inform->size_a; i++)
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
