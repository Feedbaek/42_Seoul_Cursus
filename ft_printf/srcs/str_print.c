/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:43:57 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/18 22:43:25 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		char_print(t_format *form, int value)
{
	int len;

	len = 1;
	if (form->left)
	{
		write(1, &value, 1);
		len = flag_print(len, form, value);
	}
	else if (form->zero)
	{
		len = flag_print(len, form, value);
		write(1, &value, 1);
	}
	else
	{
		len = flag_print(len, form, value);
		write(1, &value, 1);
	}
	return (len);
}
int		str_print(t_format *form, char *value)
{
	int		len;
	char	*str;

	str = value;
	if (form->left)
	{
		len = str_ft_putstr_fd(str, form);
		len += str_flag_print(form, value);
	}
	else
	{
		len = str_flag_print(form, value);
		len += str_ft_putstr_fd(str, form);
	}
	return (len);
}
int		percent_print(t_format *form, int value)
{
	int len;

	len = 1;
	if (form->left)
	{
		write(1, &value, 1);
		len = flag_print(len, form, value);
	}
	else if (form->zero)
	{
		len = flag_print(len, form, value);
		write(1, &value, 1);
	}
	else
	{
		len = flag_print(len, form, value);
		write(1, &value, 1);
	}
	return (len);
}
