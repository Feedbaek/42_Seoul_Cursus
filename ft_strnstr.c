/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:15:36 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/09 15:35:13 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t i;

	if (!substr[0])
		return ((char*)str);
	while ((unsigned char)*str != 0 && len > 0)
	{
		i = 0;
		while ((unsigned char)str[i] == (unsigned char)substr[i] && i < len)
		{
			i++;
			if ((unsigned char)substr[i] == 0)
				return ((char *)str);
		}
		str++;
		len--;
	}
	return (0);
}
