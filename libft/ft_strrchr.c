/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:01:16 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/07 22:29:34 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	if (!ft_isascii((unsigned char)c))
		return (0);
	len = ft_strlen(str);
	if ((unsigned char)c == 0)
		return ((char*)str + len);
	if (!(*str) || len == 0)
		return (0);
	while (len-- > 0)
	{
		if (!ft_isascii(str[len]))
			return (0);
		if ((unsigned char)str[len] == (unsigned char)c)
			return ((char *)str + len);
	}
	return (0);
}
