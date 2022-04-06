/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:08:45 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/13 18:21:07 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rslt;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	rslt = (char *)malloc(s1_len + s2_len + 1);
	if (!rslt)
		return (NULL);
	ft_strlcpy(rslt, s1, s1_len + 1);
	ft_strlcat(rslt, s2, s1_len + s2_len + 1);
	return (rslt);
}
