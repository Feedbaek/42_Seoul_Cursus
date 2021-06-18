/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:43:57 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/18 16:23:54 by minskim2         ###   ########.fr       */
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
	len = ft_strlen(str);
	if (form->left)
	{
		len = ft_putstr_fd(str, len, form);
		len = flag_print(len, form, value);
	}
	else
	{
		len = flag_print(len, form, value);
		len = ft_putstr_fd(str, len, form);
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
