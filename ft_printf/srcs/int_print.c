/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:39:00 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/21 22:02:37 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_print(t_format *form, int value)
{
	int		len;
	char	*str;

	if (!(str = ft_itoa(value)))
		return (-1);
	len = 0;
	if (form->left)
	{
		len += ft_putstr_fd(str, form);
		len += flag_print(form, str);
	}
	else
	{
		len += flag_print(form, str);
		len += ft_putstr_fd(str, form);
	}
	free(str);
	return (len);
}

int		unint_print(t_format *form, unsigned int value)
{
	int		len;
	char	*str;

	if (!(str = ft_itoa(value)))
		return (-1);
	len = 0;
	if (form->left)
	{
		len += ft_putstr_fd(str, form);
		len += flag_print(form, str);
	}
	else
	{
		len += flag_print(form, str);
		len += ft_putstr_fd(str, form);
	}
	free(str);
	return (len);
}
