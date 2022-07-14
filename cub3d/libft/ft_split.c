/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:45:33 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:20:06 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *word, char c)
{
	size_t	len;

	len = 0;
	while (word[len] != c && word[len] != '\0')
		len++;
	return (len);
}

static char	**ft_split_str(char **split_arr, char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			split_arr[j] = ft_substr(s, i, ft_wordlen(&s[i], c));
			if (!split_arr[j])
			{
				ft_free2d(split_arr);
				return (NULL);
			}
			j++;
			i += ft_wordlen(&s[i], c);
		}
		else
			i++;
	}
	return (split_arr);
}

char	**ft_split(char const *s, char c)
{
	size_t		cnt_word;
	char		**split_arr;

	if (!s)
		return (NULL);
	cnt_word = ft_cntword(s, c);
	split_arr = ft_calloc(cnt_word + 1, sizeof(char *));
	if (!split_arr)
		return (NULL);
	split_arr = ft_split_str(split_arr, s, c);
	return (split_arr);
}
