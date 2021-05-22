/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:23:15 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/16 18:44:40 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_valid_set(char const *s1, char const *set, size_t *i, size_t *j)
{
	if (!s1 || !set)
		return (0);
	*i = 0;
	*j = ft_strlen(s1);
	return (1);
}

static char	*null_str(void)
{
	char *str;

	str = (char*)malloc(1);
	*str = 0;
	return (str);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*tmp;
	size_t	i;
	size_t	j;

	if (!is_valid_set(s1, set, &i, &j))
		return (0);
	while (ft_strchr(set, s1[i]) && i < j && s1[i])
		i++;
	if (i == j || !s1[i])
		return (null_str());
	j--;
	while (ft_strrchr(set, s1[j]) && j > i)
		j--;
	str = (char*)malloc(sizeof(char) * (j - i + 2));
	if (!str)
		return (0);
	tmp = str;
	while (s1[i] && i <= j)
		*tmp++ = (unsigned char)s1[i++];
	*tmp = 0;
	return (str);
}
