/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:00:13 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/07 22:29:29 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*insert_word(char *str, char c)
{
	size_t	len;
	size_t	i;
	char	*word;

	i = 0;
	len = 0;
	while ((unsigned char)str[len] != (unsigned char)c && str[len])
		len++;
	if (!(word = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static size_t	cnt_word(char const *s, char c)
{
	char	*str;
	size_t	word;

	str = (char*)s;
	word = 0;
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
		{
			str++;
			continue ;
		}
		word++;
		while ((unsigned char)*str != (unsigned char)c && *str)
			str++;
	}
	return (word);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	char	*str;
	size_t	i;
	size_t	word;

	i = 0;
	if (!s)
		return (0);
	word = cnt_word(s, c);
	if (!(ret = (char**)malloc(sizeof(char*) * (word + 1))))
		return (0);
	str = (char*)s;
	while (i < word && *str)
	{
		if ((unsigned char)*str == (unsigned char)c)
		{
			str++;
			continue ;
		}
		ret[i] = insert_word(str, c);
		str += ft_strlen(ret[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
