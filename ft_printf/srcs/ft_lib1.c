/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:56:06 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/21 18:21:18 by minskim2         ###   ########.fr       */
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

int				flag_print(t_format *form, char *value)
{
	int i;
	int len;
	int n;

	n = ft_strlen(value);
	if (*value == '0' && form->precision == 0)
		n = 0;
	len = 0;
	i = 0;
	if (*value == '-')
		i++;
	if (form->zero != 1)
	{
		while (n < form->width && form->precision + i < form->width)
		{
			len += write(1, " ", 1);
			i++;
			n++;
		}
	}
	return (len);
}

int				str_flag_print(t_format *form, char *value)
{
	int i;
	int len;
	int n;

	len = 0;
	n = ft_strlen(value);
	while (n < form->width)
	{
		len += write(1, " ", 1);
		n++;
	}
	return (len);
}
