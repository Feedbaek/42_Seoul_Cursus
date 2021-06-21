/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 21:41:35 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/21 17:52:48 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		char_flag_print(t_format *form, char *value)
{
	int i;
	int len;
	int n;

	len = 0;
	n = ft_strlen(value);
	if (!n)
		n++;
	while (n < form->width)
	{
		len += write(1, " ", 1);
		n++;
	}
	return (len);
}

int		hex_flag_print(t_format *form, char *value)
{
	int i;
	int len;
	int n;

	n = ft_strlen(value);
	len = 0;
	i = 0;
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

int		ft_puthex_fd(char *s, t_format *form)
{
	int n;
	int nbr;
	int i;
	int len;

	len = 0;
	i = 0;
	n = ft_strlen(s);
	if (*(s + 2) == '0' && *(s + 3) == 0 && form->precision == 0)
	{
		if (form->left)
			len += write(1, "0x", 2);
		n -= 2;
		while (i < n && i + 2 < form->width)
		{
			len += write(1, " ", 1);
			i++;
		}
		if (!form->left)
			len += write(1, "0x", 2);
	}
	else
		len += write(1, s, ft_strlen(s));
	return (len);
}

int		x_flag_print(t_format *form, char *s)
{
	int i;
	int len;
	int n;

	n = ft_strlen(s);
	len = 0;
	i = 0;
	if (form->zero != 1)
	{
		if (form->precision > n)
			while (form->precision + i++ < form->width)
				len += write(1, " ", 1);
		else
			while (n++ < form->width)
				len += write(1, " ", 1);
	}
	else
		while (n++ < form->width)
			len += write(1, "0", 1);
	return (len);
}

int		ft_putx_fd(char *s, t_format *form)
{
	int n;
	int nbr;
	int i;
	int len;

	len = 0;
	i = 0;
	n = ft_strlen(s);
	if (form->precision >= 0)
	{
		while (n + i++ < form->precision)
			len += write(1, "0", 1);
		if (*s == '0' && n == 1 && form->precision == 0)
		{
			if (form->width > 0)
				len += write(1, " ", 1);
		}
		else
			len += write(1, s, n);
	}
	else
	{
		len += write(1, s, n);
	}
	return (len);
}
