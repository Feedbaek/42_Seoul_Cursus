/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:12:19 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/14 21:18:36 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	counter(int n, int power)
{
	int		count;

	count = 0;
	while (n < power)
	{
		power /= 10;
		count++;
	}
	return (count);
}

static void	print(int n, int power, int count, int fd)
{
	char	temp;

	while (n != 0)
	{
		temp = (n / power) + '0';
		write(fd, &(temp), 1);
		n %= power;
		power /= 10;
		count--;
	}
	while (count != 0)
	{
		write(fd, "0", 1);
		count--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		power;
	int		counts;

	power = 1000000000;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", 1);
		}
		counts = 10 - counter(n, power);
		while (n < power)
			power /= 10;
		print(n, power, counts, fd);
	}
}
