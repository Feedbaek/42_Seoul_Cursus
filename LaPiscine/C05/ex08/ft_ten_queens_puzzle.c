/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:42:39 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/06 16:56:24 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_queens[10];
int			g_n;

int			check(int x)
{
	int		i;

	i = 1;
	while (x - i >= 0)
	{
		if (g_queens[x - i] == g_queens[x] - i)
			return (0);
		if (g_queens[x - i] == g_queens[x] + i)
			return (0);
		if (g_queens[x - i] == g_queens[x])
			return (0);
		i++;
	}
	return (1);
}

void		print(void)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = g_queens[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	g_n++;
}

void		recursive(int x)
{
	int	i;

	i = 0;
	if (x == 10)
	{
		print();
		return ;
	}
	while (i < 10)
	{
		g_queens[x] = i;
		if (check(x))
			recursive(x + 1);
		i++;
	}
	return ;
}

int			ft_ten_queens_puzzle(void)
{
	int	i;
	int	x;

	g_n = 0;
	i = 0;
	while (i < 10)
		g_queens[i++] = 0;
	recursive(0);
	x = g_n;
	return (x);
}
