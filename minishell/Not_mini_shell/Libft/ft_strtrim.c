/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:13:50 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/13 18:21:45 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(char const *s1, char const *set)
{
	size_t		start;
	size_t		idx;

	start = 0;
	while (s1[start])
	{
		idx = 0;
		while (set[idx])
		{
			if (set[idx] == s1[start])
				break ;
			idx++;
		}
		if (!set[idx])
			break ;
		start++;
	}
	return (start);
}

static size_t	get_end(char const *s1, char const *set)
{
	size_t		end;
	size_t		idx;

	end = 0;
	while (end < ft_strlen(s1))
	{
		idx = 0;
		while (set[idx])
		{
			if (set[idx] == s1[ft_strlen(s1) - end - 1])
				break ;
			idx++;
		}
		if (!set[idx])
			break ;
		end++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rslt;
	size_t	start;
	size_t	end;

	start = get_start(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = get_end(s1, set);
	rslt = (char *)malloc(ft_strlen(s1) - start - end + 1);
	if (!rslt)
		return (NULL);
	ft_strlcpy(rslt, (s1 + start), ft_strlen(s1) - start - end + 1);
	return (rslt);
}
