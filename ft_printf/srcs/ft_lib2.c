/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:59:58 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/18 22:04:53 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		cnt_hsize(long long n)
{
	int size;

	size = 1;
	while (n)
	{
		n /= 16;
		if (n)
			size++;
	}
	return (size);
}

static void		iterative_sum(char *str, long long n, int idx, char *hex)
{
	while (n)
	{
		str[idx--] = (unsigned char)hex[n % 16];
		n /= 16;
	}
}

char			*ft_hextoa(long long n)
{
	int		size;
	char	*str;
	char	*hex;

	hex = "0123456789abcdef";
	size = cnt_hsize(n);
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	if (n / 16)
		iterative_sum(str, n / 16, size - 2, hex);
	str[size - 1] = (unsigned char)(hex[n % 16]);
	str[size] = 0;
	return (str);
}
