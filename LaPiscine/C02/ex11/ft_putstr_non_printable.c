/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 03:56:36 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/01 11:15:43 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_printable(unsigned char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

void	write_h(unsigned char c)
{
	c += '0';
	if (c > '9')
		c += 39;
	write(1, &c, 1);
}

void	print_hex(unsigned char c)
{
	write(1, "\\", 1);
	write_h((int)c / 16);
	write_h((int)c % 16);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (!is_printable(*str))
			print_hex(*str);
		else
			write(1, str, 1);
		str++;
	}
}
