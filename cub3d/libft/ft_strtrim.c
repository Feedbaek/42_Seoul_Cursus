/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:48:06 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:12:37 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isinset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isinset(s1[start], set))
		start++;
	if (start == end + 1)
		return (ft_strdup(""));
	while (ft_isinset(s1[end], set))
		end--;
	if (end == 0)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}
