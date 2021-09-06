/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:00:13 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/06 15:47:52 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

int	cnt_word(char *str, char c)
{
	int		word;

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

char	**ft_split(char *str, char c)
{
	char	**ret;
	int		i;
	int		cnt;

	i = 0;
	cnt = cnt_word(str, c);
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!ret)
		return (0);
	while (i < cnt && *str)
	{
		if ((unsigned char)*str == (unsigned char)c)
		{
			str++;
			continue ;
		}
		ret[i] = insert_word(str, c);
		if (!ret)
			return (mem_free(ret, i));
		str += ft_strlen(ret[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
