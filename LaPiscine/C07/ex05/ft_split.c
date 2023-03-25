/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:48:16 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/12 00:40:25 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

void	ft_strcpy(char *dest, char *from, char *to)
{
	while (from < to)
	{
		*dest = *from;
		dest++;
		from++;
	}
	*dest = 0;
}

int		ft_cnt(char *str, char *charset)
{
	int flag;
	int cnt;

	cnt = 0;
	flag = 1;
	while (*str)
	{
		if (flag && !is_in_charset(*str, charset))
		{
			cnt++;
			flag = 0;
		}
		if (is_in_charset(*str, charset))
			flag = 1;
		str++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	int		idx;
	int		size;
	char	*ptr;
	char	**ret;

	size = ft_cnt(str, charset);
	ret = (char **)malloc(sizeof(char *) * size + 1);
	idx = 0;
	while (*str)
	{
		if (!is_in_charset(*str, charset))
		{
			ptr = str;
			while (*str && !is_in_charset(*str, charset))
				str++;
			ret[idx] = (char *)malloc(str - ptr + 1);
			ft_strcpy(ret[idx], ptr, str);
			idx++;
		}
		str++;
	}
	ret[size] = 0;
	return (ret);
}
