/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:39:00 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/15 20:58:27 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_print(const char *s, t_format *form, int i)
{
	int		len;
	int		idx;
	char	*str;

	idx = 0;
	if (!(str = ft_itoa(form->value)))
		return (0);
	len = ft_strlen(str);
	if (form->left)
	{
		ft_putstr_fd(str, 1);
		while (len++ < form->width)
			write(1, " ", 1);
	}
	else if (form->zero)
	{
		while (len++ < form->width)
			write(1, "0", 1);
		ft_putstr_fd(str, 1);
	}
	else
	{
		while (len++ < form->width)
			write(1, " ", 1);
		ft_putstr_fd(str, 1);
	}
	free(str);
	return (len);
}
int		unint_print(const char *str, t_format *form, int i)
{

}
