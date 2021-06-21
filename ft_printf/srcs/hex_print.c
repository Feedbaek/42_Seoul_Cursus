/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:42:19 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/21 20:46:03 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	put_xl(char *str)
{
	while (*str)
	{
		if ((unsigned char)*str >= 'a' && (unsigned char)*str <= 'z')
			*str = *str - 32;
		str++;
	}
}

int				x_print(t_format *form, unsigned int value)
{
	int		len;
	char	*str;

	if (!(str = ft_hextoa(value)))
		return (0);
	len = 0;
	if (form->left)
	{
		len += ft_putx_fd(str + 2, form);
		len += x_flag_print(form, str + 2);
	}
	else
	{
		len += x_flag_print(form, str + 2);
		len += ft_putx_fd(str + 2, form);
	}
	free(str);
	return (len);
}

int				xl_print(t_format *form, unsigned int value)
{
	int		len;
	char	*str;

	if (!(str = ft_hextoa(value)))
		return (0);
	put_xl(str + 2);
	len = 0;
	if (form->left)
	{
		len += ft_putx_fd(str + 2, form);
		len += x_flag_print(form, str + 2);
	}
	else
	{
		len += x_flag_print(form, str + 2);
		len += ft_putx_fd(str + 2, form);
	}
	free(str);
	return (len);
}

int				addr_print(t_format *form, void *value)
{
	int		len;
	char	*str;

	if (!(str = ft_hextoa((unsigned long)value)))
		return (0);
	len = 0;
	if (form->left)
	{
		len += ft_puthex_fd(str, form);
		len += hex_flag_print(form, str);
	}
	else
	{
		len += hex_flag_print(form, str);
		len += ft_puthex_fd(str, form);
	}
	free(str);
	return (len);
}
