/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:04:56 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/15 17:42:20 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	run_cmd_1(char *cmd, t_inform *inform)
{
	if (ft_strncmp(cmd, "ra", 2) == 0)
		ra(inform);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		rb(inform);
	else if (ft_strncmp(cmd, "sa", 2) == 0)
		sa(inform);
	else if (ft_strncmp(cmd, "sb", 2) == 0)
		sb(inform);
	else if (ft_strncmp(cmd, "ss", 2) == 0)
		ss(inform);
	else if (ft_strncmp(cmd, "rr", 2) == 0)
		rr(inform);
	else if (ft_strncmp(cmd, "pa", 2) == 0)
		pa(inform);
	else if (ft_strncmp(cmd, "pb", 2) == 0)
		pb(inform);
}

void	run_cmd(char *cmd, t_inform *inform)
{
	if (ft_strlen(cmd) == 3)
	{
		if (ft_strncmp(cmd, "rra", 3) == 0)
			rra(inform);
		else if (ft_strncmp(cmd, "rrb", 3) == 0)
			rrb(inform);
		else if (ft_strncmp(cmd, "rrr", 3) == 0)
			rrr(inform);
	}
	else
		run_cmd_1(cmd, inform);
}

int	main(int argc, char *argv[])
{
	t_inform	inform;
	int			status;
	char		*line;

	if (argc < 2)
		return (0);
	init_stack(&inform, argc, argv);
	inform.checker = 0;
	status = 1;
	while (status == 1)
	{
		status = get_next_line(0, &line);
		if (status == -1)
			error_push_swap("Error\n");
		run_cmd(line, &inform);
		free(line);
	}
	if (is_sorted(inform.stack_a, inform.size_a, 0) && inform.size_b == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
