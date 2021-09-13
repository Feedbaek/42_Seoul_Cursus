/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:31:12 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 18:32:18 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
		}
		if (inform.size_a == 5)
		{
			sort_5(&inform, len);
			sort_end(&inform);
		}
		return (0);
	}
	first_a_to_b(&inform, inform.size_a);
	return (0);
}
