/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:43:57 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/21 22:11:44 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*char_to_str(int value)
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (0);
	str[0] = (unsigned char)value;
	str[1] = 0;
	return (str);
}

int				char_print(t_format *form, int value)
{
	int		len;
	char	*str;

	if (!value)
		str = "";
	else if (!(str = char_to_str(value)))
		return (-1);
	len = 0;
	if (form->left)
	{
		len += write(1, str, 1);
		len += char_flag_print(form, str);
	}
	else
	{
		len += char_flag_print(form, str);
		len += write(1, str, 1);
	}
	if (value)
		free(str);
	return (len);
}

int				str_print(t_format *form, char *value)
{
	int		len;

	len = 0;
	if (!value)
		value = "(null)";
	if (form->left)
	{
		len += str_ft_putstr_fd(value, form);
		len += str_flag_print(form, value);
	}
	else
	{
		len += str_flag_print(form, value);
		len += str_ft_putstr_fd(value, form);
	}
	return (len);
}

static	int		per_flag_print(t_format *form)
{
	int n;
	int len;

	len = 0;
	n = 1;
	if (form->zero)
	{
		while (n++ < form->width)
			len += write(1, "0", 1);
	}
	else
	{
		while (n++ < form->width)
			len += write(1, " ", 1);
	}
	return (len);
}

int				percent_print(t_format *form, int value)
{
	int		len;
	char	c;

	c = (char)value;
	len = 0;
	if (form->left)
	{
		len += write(1, &c, 1);
		len += per_flag_print(form);
	}
	else
	{
		len += per_flag_print(form);
		len += write(1, &c, 1);
	}
	return (len);
}
