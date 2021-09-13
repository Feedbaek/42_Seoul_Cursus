/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:30:02 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 20:59:24 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*s;

	s = (unsigned char *)src;
	tmp = (unsigned char *)dest;
	while (n--)
		*tmp++ = *s++;
	return (dest);
}

int	ft_isascii(int c)
{
	if (c > 255)
		return (0);
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (!ft_isascii(s1[i]) || !ft_isascii(s2[i]))
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	if (i == n && i != 0)
		i--;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

void	error_push_swap(char *error)
{
	ft_putstr(error);
	exit(0);
}
