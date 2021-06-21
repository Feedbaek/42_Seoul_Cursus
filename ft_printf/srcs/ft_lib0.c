/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:54:45 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/21 20:09:01 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t	cnt;

	if (!str)
		return (0);
	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

int			ft_atoi(const char *str)
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

int			ft_putstr_fd(char *s, t_format *form)
{
	int n;
	int len;

	len = 0;
	n = ft_strlen(s);
	if (*s == '-')
		len += write(1, "-", 1);
	if (form->zero == 1 && !form->dot)
		while (n++ < form->width)
			len += write(1, "0", 1);
	else
	{
		if (*s == '-')
			s++;
		n = ft_strlen(s);
		while (form->precision > n++)
			len += write(1, "0", 1);
	}
	if (*s == '-')
		s++;
	if (*s != '0' || ft_strlen(s) != 1 || form->precision != 0)
		len += write(1, s, ft_strlen(s));
	return (len);
}

static	int	print_strlen(int i, int n, t_format *form)
{
	int len;

	len = 0;
	while (i < n && i < form->width)
	{
		len += write(1, " ", 1);
		i++;
	}
	return (len);
}

int			str_ft_putstr_fd(char *s, t_format *form)
{
	int len;
	int i;
	int a;
	int n;

	len = 0;
	n = ft_strlen(s);
	i = form->precision < n && form->precision >= 0 ?
	form->precision : n;
	a = 0;
	if (form->left)
	{
		while (a < i)
			len += write(1, s + (a++), 1);
		len += print_strlen(i, n, form);
	}
	else
	{
		len += print_strlen(i, n, form);
		while (a < i)
			len += write(1, s + (a++), 1);
	}
	return (len);
}
