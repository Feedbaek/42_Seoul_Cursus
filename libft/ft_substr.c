/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:40:43 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/07 22:29:36 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (start >= ft_strlen(s))
	{
		str[0] = 0;
		return (str);
	}
	while (i < len && s[start + i])
	{
		str[i] = (unsigned char)s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
