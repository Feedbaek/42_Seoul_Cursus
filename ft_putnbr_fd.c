/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:14:46 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/08 17:42:19 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_putnbr(int n, int fd)
{
	char	c;

	if (n / 10)
		rec_putnbr(n / 10, fd);
	c = (unsigned char)('0' + (n % 10));
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
		write(fd, "-", 1);
	if (n < 0)
	{
		if (-(n / 10))
			rec_putnbr(-(n / 10), fd);
		c = (unsigned char)('0' - (n % 10));
		write(fd, &c, 1);
	}
	else
	{
		if (n / 10)
			rec_putnbr(n / 10, fd);
		c = (unsigned char)('0' + (n % 10));
		write(fd, &c, 1);
	}
}
