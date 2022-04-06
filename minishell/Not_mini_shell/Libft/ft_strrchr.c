/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:52:09 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/16 16:16:21 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;
	char	*temp;

	idx = ft_strlen(s);
	temp = (char *)s;
	if (!c)
		return (temp + idx);
	while (idx != (size_t)(-1))
	{
		if (temp[idx] == (char)c)
			return (temp + idx);
		idx--;
	}
	return (NULL);
}
