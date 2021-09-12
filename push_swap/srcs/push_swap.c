/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:31:12 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/12 17:54:56 by minskim2         ###   ########.fr       */
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
	printf("stack_b: ");
	while (i < inform->size_b)
	{
		printf("%d ", inform->stack_b[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_inform	inform;
	int			len;

	if (argc < 2)
		return (0);
	init_stack(&inform, argc, argv);
	if (is_sorted(inform.stack_a, inform.size_a, 0))
		return (0);
	if (inform.size_a <= 5)
	{
		len = find_long_section(&inform);
		if (inform.size_a == 2 || inform.size_a == 3)
		{
			sort_2_3(&inform);
			sort_end(&inform);
			return (0);
		}
		if (inform.size_a == 5)
		{
			sort_5(&inform, len);
			sort_end(&inform);
			return (0);
		}
	}
	//sort_end(&inform);
	//quick_a(&inform, inform.size_a);
	//test(&inform);
	a_to_b(&inform, inform.size_a);
	//test(&inform);
	return (0);
}

