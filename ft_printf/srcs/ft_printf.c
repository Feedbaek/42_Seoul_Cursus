/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:08:16 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/14 19:51:10 by minskim2         ###   ########.fr       */
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
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	*form;
	int			size;
	int			i;

	i = 0;
	va_start(ap, format);
	f_setting(form);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!(form = (t_format*)malloc(sizeof(t_format))))
				return (-1);
			if (!f_start(format[i], form, ap))
				return (-1);
		}
		else
			write(1, format, 1);
		i++;
	}
	va_end(ap);
	return (size);
}
