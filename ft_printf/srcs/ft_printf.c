/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:08:16 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/23 02:36:51 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	f_setting(t_format *form)
{
	form->zero = 0;
	form->left = 0;
	form->width = 0;
	form->dot = 0;
	form->precision = -1;
	form->type = 0;
	form->step = 0;
}

static	int		f_start(const char *format, t_format *form, va_list ap)
{
	int	i;

	i = 0;
	f_setting(form);
	format++;
	while (!(form->type = check_type(format + i)))
	{
		if ((*(format + i) == '0' || *(format + i) == '-') && form->step == 0)
			i += check_flag(format + i, form);
		else if (form->step == 0)
			i += check_width(format + i, form, ap);
		else if (form->step == 1)
			i += check_dot(format + i, form);
		else if (form->step == 2)
			i += check_precision(format + i, form, ap);
		else
			return (0);
	}
	if (form->type)
		i += 2;
	return (i);
}

static	int		f_write(t_format *form, va_list ap)
{
	int ret;

	ret = 0;
	if (form->type == 1)
		ret = int_print(form, va_arg(ap, int));
	else if (form->type == 2)
		ret = unint_print(form, va_arg(ap, unsigned int));
	else if (form->type == 3)
		ret = x_print(form, va_arg(ap, unsigned int));
	else if (form->type == 4)
		ret = xl_print(form, va_arg(ap, unsigned int));
	else if (form->type == 5)
		ret = addr_print(form, va_arg(ap, void *));
	else if (form->type == 6)
		ret = char_print(form, va_arg(ap, int));
	else if (form->type == 7)
		ret = str_print(form, va_arg(ap, char *));
	else if (form->type == 8)
		ret = percent_print(form, '%');
	else
		ret = -1;
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	form;
	int			size;
	int			i;
	int			x;

	size = 0;
	i = 0;
	va_start(ap, format);
	while (*(format + i))
		if (format[i] == '%')
		{
			if (!(x = f_start(format + i, &form, ap)))
				return (-1);
			i += x;
			if ((x = f_write(&form, ap)) == -1)
				return (-1);
			size += x;
		}
		else
			size += write(1, format + i++, 1);
	va_end(ap);
	return (size);
}
