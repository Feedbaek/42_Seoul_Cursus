/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:06:38 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/06 10:54:42 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int o;

	if (nb >= 0)
	{
		if (nb / 10)
			ft_putnbr(nb / 10);
		o = (nb % 10) + '0';
		write(1, &o, 1);
	}
	else
	{
		write(1, "-", 1);
		if (-(nb / 10))
			ft_putnbr(-(nb / 10));
		o = -(nb % 10) + '0';
		write(1, &o, 1);
	}
}
