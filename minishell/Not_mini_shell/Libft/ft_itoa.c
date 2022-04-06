/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:14:28 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/17 15:44:51 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(int n)
{
	int			counts;
	int			power;

	counts = 0;
	power = 1000000000;
	if (n < 0)
	{
		counts++;
		n *= -1;
	}
	while (n < power)
	{
		power /= 10;
		counts++;
	}
	return (counts);
}

static int	power_calculator(int n)
{
	int			power;

	power = 1000000000;
	if (n < 0)
		n *= -1;
	while (n < power)
		power /= 10;
	return (power);
}

static char	*converter(int n, int counts, int power, int sign)
{
	char		*rslt;
	int			idx;

	idx = 0;
	rslt = (char *)malloc(11 + sign - counts);
	if (!rslt)
		return (NULL);
	if (sign)
		rslt[idx++] = '-';
	while (n != 0)
	{
		rslt[idx] = (signed char)((n / power) + '0');
		n %= power;
		power /= 10;
		idx++;
	}
	while (idx < 10 + sign - counts)
	{
		rslt[idx] = '0';
		idx++;
	}
	rslt[idx] = '\0';
	return (rslt);
}

char	*ft_itoa(int n)
{
	int			sign;
	int			counts;
	int			power;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	counts = counter(n);
	power = power_calculator(n);
	return (converter(n, counts, power, sign));
}
