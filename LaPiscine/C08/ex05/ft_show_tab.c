/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:08:42 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/10 23:20:41 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_copy(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	print_nbr(int nbr)
{
	char c;

	c = nbr % 10 + '0';
	if (nbr / 10)
		print_nbr(nbr / 10);
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		write(1, par[i].str, par[i].size);
		write(1, "\n", 1);
		print_nbr(par[i].size);
		write(1, "\n", 1);
		print_copy(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
