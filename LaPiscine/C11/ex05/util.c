/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 10:17:22 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/15 13:40:23 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	rec(int nb)
{
	char c;

	if (nb / 10)
		rec(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char c;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (-(nb / 10))
			rec(-(nb / 10));
		c = -(nb % 10) + '0';
	}
	else
	{
		if (nb / 10)
			rec(nb / 10);
		c = (nb % 10) + '0';
	}
	write(1, &c, 1);
	write(1, "\n", 1);
}

int		ft_atoi(char *str)
{
	int sum;
	int sign;

	sum = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum *= 10;
		sum += *str - '0';
		str++;
	}
	return (sign * sum);
}
