/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:07:00 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/09 01:21:08 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long	str_len(char *c)
{
	long long	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char		*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char		*error(void)
{
	char		*e;

	e = ((char *)malloc(1));
	e[0] = 0;
	return (e);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char		*p;
	char		*tmp;
	int			i;
	long long	len;

	i = 0;
	len = 0;
	if (!size)
		return (error());
	while (i < size)
		len += str_len(strs[i++]);
	p = (char *)malloc(len + (size - 1) * str_len(sep) + 1);
	tmp = ft_strcpy(p, strs[0]);
	i = 1;
	while (i < size)
	{
		tmp = ft_strcpy(tmp, sep);
		tmp = ft_strcpy(tmp, strs[i]);
		i++;
	}
	*tmp = 0;
	return (p);
}
