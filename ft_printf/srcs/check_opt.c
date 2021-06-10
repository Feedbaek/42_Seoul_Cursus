/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:00:18 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/10 22:26:31 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_cnt(char *)

int		check_flag(char *str, t_format *form)
{
	if (*str == '0')
	{
		form->zero = 1;
		if (form->left = 1)
			form->zero = 0;
	}
	else if (*str == '-')
	{
		form->left = 1;
		form->zero = 0;
	}
	else
		return (0);
	return (1);
}

int		check_width(char *str, t_format *form, va_list ap)
{
	int num;

	if (*str == '*')
	{
		if ((form->width = va_arg(ap, int)) < 0)
		{
			form->width *= -1;
			form->left = 1;
		}
	}
	else if (ft_isdigit(*str))
	{
		num = ft_atoi(str);
		form->width = ft_atoi(*str);
	}
	else
		return (0);
	return (1);
}

int		check_precision(char *str, t_format *form, va_list ap)
{
	if (*str == '*')
	{
		if ((form->precision = va_arg(ap, int)) < 0)
			form->precision = -2;
	}
	else if (ft_isdigit(*str))
	{
		if (*str < 0)
			return (0); // 음수가 들어오면 에러;
		form->precision = ft_atoi(*str);
	}
	return (1);
}
