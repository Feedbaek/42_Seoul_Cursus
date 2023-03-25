/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:31:00 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/01 19:23:59 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *g_hex;

void	print_adr(long long adr, int i)
{
	char o;

	if (!adr)
	{
		while (i < 16)
		{
			write(1, "0", 1);
			i++;
		}
		return ;
	}
	print_adr(adr / 16, i + 1);
	write(1, &g_hex[adr % 16], 1);
}

void	print_txt(unsigned char *addr, unsigned int len)
{
	unsigned int n;

	n = 0;
	while (n < len)
	{
		if (addr[n] >= ' ' && addr[n] <= '~')
			write(1, &addr[n], 1);
		else
			write(1, ".", 1);
		n++;
	}
	write(1, "\n", 1);
}

void	print_contents(unsigned char *addr, unsigned int size)
{
	unsigned char	a;
	unsigned char	b;
	unsigned int	ind;

	ind = 0;
	while (ind < size)
	{
		a = g_hex[addr[ind] / 16];
		b = g_hex[addr[ind] % 16];
		write(1, &a, 1);
		write(1, &b, 1);
		if (ind % 2 == 1)
			write(1, " ", 1);
		ind++;
	}
	while (ind < 16)
	{
		write(1, "  ", 2);
		if (ind % 2 == 1)
			write(1, " ", 1);
		ind++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned char	*tmp;
	void			*origin;

	origin = addr;
	g_hex = "0123456789abcdef";
	tmp = (unsigned char *)addr;
	i = 0;
	while (size)
	{
		if (size / 16)
			len = 16;
		else
			len = size;
		print_adr((long long)tmp + (i * 16), 0);
		write(1, ": ", 2);
		print_contents(tmp + (i * 16), len);
		print_txt(addr + (i * 16), len);
		size -= len;
		i++;
	}
	return (origin);
}
