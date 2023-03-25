/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:28:47 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/06 11:55:47 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_size;

int		error(char *base)
{
	int	i;

	if (g_size <= 1)
		return (1);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (1);
		i = 1;
		while (base[i])
		{
			if (*base == base[i])
				return (1);
			i++;
		}
		base++;
	}
	return (0);
}

void	rec_nbr(int nbr, char *base)
{
	int i;

	if (nbr / g_size)
		rec_nbr((nbr / g_size), base);
	i = nbr % g_size;
	write(1, &base[i], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	g_size = 0;
	while (base[i])
	{
		g_size++;
		i++;
	}
	if (error(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr / g_size)
			rec_nbr(-(nbr / g_size), base);
		i = -(nbr % g_size);
		write(1, &base[i], 1);
	}
	else
		rec_nbr(nbr, base);
}
