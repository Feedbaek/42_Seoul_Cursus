/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:43:21 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:19:20 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isformat(char *str, char *fmt)
{
	int		len_str;
	int		len_fmt;
	char	*start_fmt;

	len_str = ft_strlen(str);
	len_fmt = ft_strlen(fmt);
	if (len_str <= len_fmt)
		return (0);
	start_fmt = str + len_str - len_fmt;
	if (ft_strncmp(start_fmt, fmt, len_fmt) == 0)
		return (1);
	return (0);
}
