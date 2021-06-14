/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:00:18 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/14 19:43:54 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_dot(char *str, t_format *form)
{
	if (*str == '.')
	{
		form->dot = 1;
		return (1);
	}
	return (0);
}

int		check_flag(char *str, t_format *form)
{
	if (*str == '0')
	{
		form->zero = 1;
		if (form->left == 1)
			form->zero = 0;
		form->step = 1;
		return (1);
	}
	if (*str == '-')
	{
		form->left = 1;
		form->zero = 0;
		form->step = 1;
		return (1);
	}
	return (0);
}

int		check_width(char *str, t_format *form, va_list ap)
{
	int x;

	if (*str == '*')
	{
		if ((form->width = va_arg(ap, int)) < 0)
		{
			form->width *= -1;
			form->left = 1;
		}
		form->step = 2;
		return (1);
	}
	else if ((x = ft_atoi(*str)))
	{
		if (x < 0)
		{
			form->left = 1;
			x *= -1;
		}
		form->width = x;
		form->step = 2;
		return (1);
	}
	return (0);
}

int		check_precision(char *str, t_format *form, va_list ap)
{
	int x;

	if (*str == '*')
	{
		if ((form->precision = va_arg(ap, int)) < 0)
			form->precision = -2;
		form->step = 3;
		return (1);
	}
	if ((x = ft_atoi(*str)) || *str == '0')
	{
		if (x < 0)
			return (0);
		form->precision = x;
		form->step = 3;
		return (1);
	}
	return (0);
}

int		check_type(char *str)
{
	if (*str == 'd' || *str == 'i')
		return (1);
	if (*str == 'u')
		return (2);
	if (*str == 'x')
		return (3);
	if (*str == 'X')
		return (4);
	if (*str == 'p')
		return (5);
	if (*str == 'c')
		return (6);
	if (*str == 's')
		return (7);
	if (*str == '%')
		return (8);
	return (0);
}
