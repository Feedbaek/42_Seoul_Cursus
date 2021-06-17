/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:43:57 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/17 21:52:57 by minskim2         ###   ########.fr       */
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
		len = flag_print(len, form);
	}
	else if (form->zero)
	{
		len = flag_print(len, form);
		write(1, &value, 1);
	}
	else
	{
		len = flag_print(len, form);
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
		ft_putstr_fd(str, 1);
		len = flag_print(len, form);
	}
	else
	{
		len = flag_print(len, form);
		ft_putstr_fd(str, 1);
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
		len = flag_print(len, form);
	}
	else if (form->zero)
	{
		len = flag_print(len, form);
		write(1, &value, 1);
	}
	else
	{
		len = flag_print(len, form);
		write(1, &value, 1);
	}
	return (len);
}
