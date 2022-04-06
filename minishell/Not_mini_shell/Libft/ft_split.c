/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:19:23 by sungmcho          #+#    #+#             */
/*   Updated: 2022/03/01 20:20:24 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_memfree(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static int	c_w(char const *s, char c)
{
	int				counts;
	int				word_in;
	int				idx;

	counts = 0;
	word_in = 0;
	idx = -1;
	while (s[++idx])
	{
		if (s[idx] == c)
		{
			if (word_in)
			{
				word_in = 0;
				counts++;
			}
		}
		else
			word_in = 1;
	}
	if (word_in)
		counts++;
	return (counts);
}

char	**ft_split(char const *s, char c)
{
	char const	*break_point;
	char		**rslt;
	size_t		i;

	rslt = (char **)malloc(sizeof(char *) * (c_w(s, c) + 1));
	if (!rslt)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			break_point = s;
			while (*s && *s != c)
				++s;
			rslt[i] = (char *)malloc(s - break_point + 1);
			if (!rslt[i])
				return (ft_memfree(rslt));
			ft_strlcpy(rslt[i++], break_point, (size_t)(s - break_point + 1));
		}
		else
			++s;
	}
	rslt[i] = 0;
	return (rslt);
}
