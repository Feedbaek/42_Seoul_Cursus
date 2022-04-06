/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:11:15 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/16 16:16:18 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t limit)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	if (!ft_strlen(haystack) || limit < ft_strlen(needle))
		return (NULL);
	i = 0;
	while (i + ft_strlen(needle) <= limit && haystack[i])
	{
		if (haystack[i] == needle[0] && !ft_memcmp(
				&haystack[i], &needle[0], ft_strlen(needle)))
			return ((char *)haystack + i);
		++i;
	}
	return (NULL);
}
