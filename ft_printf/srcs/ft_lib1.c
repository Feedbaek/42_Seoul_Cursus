/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:56:06 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/15 20:10:43 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		cnt_size(int n)
{
	int size;

	size = 1;
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		if (n)
			size++;
	}
	return (size);
}

static void		iterative_sum(char *str, int n, int idx)
{
	while (n)
	{
		str[idx--] = n % 10 + '0';
		n /= 10;
	}
}

char			*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = cnt_size(n);
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	if (n < 0)
	{
		if (-(n / 10))
			iterative_sum(str, -(n / 10), size - 2);
		str[size - 1] = (unsigned char)('0' - (n % 10));
		str[0] = '-';
	}
	else
	{
		if (n / 10)
			iterative_sum(str, n / 10, size - 2);
		str[size - 1] = (unsigned char)('0' + (n % 10));
	}
	str[size] = 0;
	return (str);
}
