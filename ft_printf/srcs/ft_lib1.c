/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:56:06 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/18 22:56:01 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				cnt_size(long long n)
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

static void		iterative_sum(char *str, long long n, int idx)
{
	while (n)
	{
		str[idx--] = n % 10 + '0';
		n /= 10;
	}
}

char			*ft_itoa(long long n)
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

int		flag_print(int len, t_format *form, long long value)
{
	int i;

	i = 0;
	if (value < 0)
		i++;
	if (form->zero != 1)
		while (len < form->width && form->precision + i < form->width)
		{
			write(1, " ", 1);
			len++;
			i++;
		}
	return (len);
}

int		str_flag_print(t_format *form, char *value)
{
	int i;
	int len;
	int n;

	n = ft_strlen(value);
	i = form->precision;
	len = 0;
	if (i > n)
		while (n < form->width)
		{
			write(1, " ", 1);
			n++;
			len++;
		}
	else
		while (i < form->width)
		{
			write(1, " ", 1);
			i++;
			len++;
		}
	return (len);
}
