/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyeon <donghyeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:22:59 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/07 20:23:10 by donghyeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			result = (char *)s;
		s++;
	}
	if (result != 0)
		return (result);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
