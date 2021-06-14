/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:08:16 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/14 22:38:28 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_setting(t_format *form)
{
	form->zero = 0;
	form->left = 0;
	form->width = 0;
	form->dot = 0;
	form->precision = -1;
	form->type = 0;
	form->step = 0;
}

int		f_start(const char *format, t_format *form, va_list *ap)
{
	int	i;

	i = 0;
	while (!(form->type = check_type(format + i)))
	{
		if (form->step == 0)
			i += check_flag(format + i, form);
		else if (form->step == 1)
			i += check_width(format + i, form);
		else if (form->step == 2)
			i += check_dot(format + i, form));
		else if (form->step == 2 && form->dot == 1)
			i += check_precision(format + i, form));
		else
			return (0);
	}
	return (i);
}

int		f_write(const char *format, t_format *form, int i)
{
	int ret;

	ret = 0;
	if (form->type == 1)
		ret = int_print(format, form, i);
	else if (form->type == 2)
		ret = unint_print(format, form, i);
	else if (form->type == 3)
		ret = x_print(format, form, i);
	else if (form->type == 4)
		ret = xl_print(format, form, i);
	else if (form->type == 5)
		ret = addr_print(format, form, i);
	else if (form->type == 6)
		ret = char_print(format, form, i);
	else if (form->type == 7)
		ret = str_print(format, form, i);
	else if (form->type == 8)
		ret = percent_print(format, form, i);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	*form;
	int			size;
	int			i;

	size = 0;
	va_start(ap, format);
	while (format)
	{
		i = 0;
		if (format[i] == '%')
		{
			if (!(form = (t_format*)malloc(sizeof(t_format))))
				return (-1);
			f_setting(form);
			if (!(i = f_start(format, form, ap)))
				return (-1);
			if (!(size = f_write(format, form, i)))
		}
		else
		{
			write(1, format, 1);
			size++;
		}
		format++;
		size++;
	}
	write(1, "\n", 1);
	va_end(ap);
	return (size);
}
