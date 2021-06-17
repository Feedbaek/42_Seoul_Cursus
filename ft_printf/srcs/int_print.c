/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:39:00 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/17 22:32:08 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_print(t_format *form, int value)
{
	int		len;
	char	*str;

	if (!(str = ft_itoa(value)))
		return (0);
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
	free(str);
	return (len);
}
int		unint_print(t_format *form, unsigned int value)
{
	int		len;
	char	*str;

	if (!(str = ft_itoa(value)))
		return (0);
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
	free(str);
	return (len);
}
