/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:48:01 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:20:26 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*begin;

	begin = (char *)s;
	while (*s)
		s++;
	while (s >= begin)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
