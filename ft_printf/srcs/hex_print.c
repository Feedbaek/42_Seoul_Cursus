/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:42:19 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/18 16:26:18 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	put_xl(char *str)
{
	char c;

	while (*str)
	{
		c = *str;
		if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
			c -= 32;
		write(1, &c, 1);
		str++;
	}
}

int				x_print(t_format *form, unsigned int value)
{
	int		len;
	char	*str;

	if (!(str = ft_hextoa(value)))
		return (0);
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
	free(str);
	return (len);
}
int				xl_print(t_format *form, unsigned int value)
{
	int		len;
	char	*str;

	if (!(str = ft_hextoa(value)))
		return (0);
	len = ft_strlen(str);
	if (form->left)
	{
		put_xl(str);
		len = flag_print(len, form, value);
	}
	else
	{
		len = flag_print(len, form, value);
		put_xl(str);
	}
	free(str);
	return (len);
}
int				addr_print(t_format *form, void * value)
{
	int		len;
	char	*str;

	if (!(str = ft_hextoa((long long)value)))
		return (0);
	len = ft_strlen(str) + 2;
	if (form->left)
	{
		write(1, "0x", 2);
		len =ft_putstr_fd(str, len, form);
		len = flag_print(len, form, (long long)value);
	}
	else
	{
		len = flag_print(len, form, (long long)value);
		write(1, "0x", 2);
		len = ft_putstr_fd(str, len, form);
	}
	free(str);
	return (len);
}
