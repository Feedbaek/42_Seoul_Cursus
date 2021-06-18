/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:54:45 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/18 22:44:38 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

int		ft_atoi(const char *str)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	while (*str == '\t'
			|| *str == ' '
			|| *str == '\n'
			|| *str == '\f'
			|| *str == '\v'
			|| *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		i *= 10;
		i += *str - '0';
		str++;
	}
	return (sign * i);
}

int		ft_putstr_fd(char *s, int len, t_format *form)
{
	int n;
	int i;

	n = ft_strlen(s);
	if (*s == '-')
	{
		write(1, "-", 1);
		s++;
		n--;
	}
	if (form->zero == 1 && !form->dot)
		while (len < form->width)
		{
			write(1, "0", 1);
			len++;
		}
	else
		while (form->precision > n)
		{
			write(1, "0", 1);
			n++;
			len++;
		}
	i = 0;
	if (*s == '0' && n > form->precision && form->precision == 0)
	{
		while (n > form->precision + i && form->width > i)
		{
			write(1, " ", 1);
			i++;
		}
	}
	else
		write(1, s, ft_strlen(s));
	return (len);
}

int		str_ft_putstr_fd(char *s, t_format *form)
{
	int i;
	int n;
	int len;

	n = ft_strlen(s);
	i = 0;
	if (n > form->precision && form->precision != -1)
	{
		len += write(1, s, form->precision);
		while (n > form->precision + i && form->width > i + len)
		{
			write(1, " ", 1);
			len++;
			i++;
		}
	}
	else
	{
		write(1, s, ft_strlen(s));
		len++;
	}
	return (len);
}
