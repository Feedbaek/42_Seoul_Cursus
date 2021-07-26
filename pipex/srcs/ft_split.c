/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:52:14 by minskim2          #+#    #+#             */
/*   Updated: 2021/07/26 15:54:24 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**mem_free(char **ret, int i)
{
	int	idx;

	idx = 0;
	while (idx < i)
		free(ret[i++]);
	return (0);
}

static char	*insert_word(char *str, char c)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	len = 0;
	while ((unsigned char)str[len] != (unsigned char)c && str[len])
		len++;
	word = (char *)malloc(sizeof(char) * len + 1);
	if (!word)
		return (0);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static int	cnt_word(char const *s, char c)
{
	char	*str;
	int		word;

	str = (char *)s;
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

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*str;
	int		i;
	int		word;

	i = 0;
	word = cnt_word(s, c);
	ret = (char **)malloc(sizeof(char *) * (word + 1));
	if (!ret)
		return (0);
	str = (char *)s;
	while (i < word && *str)
	{
		if ((unsigned char)*str == (unsigned char)c)
		{
			str++;
			continue ;
		}
		ret[i] = insert_word(str, c);
		if (!ret[i])
			return (mem_free(ret, i));
		str += ft_strlen(ret[i++]);
	}
	ret[i] = 0;
	return (ret);
}
