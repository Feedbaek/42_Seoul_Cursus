/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyeon <donghyeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:09:21 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/07 20:17:47 by donghyeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_sep(char c, char charset)
{
	if (c == charset)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

static int	ft_count_numb_of_word(char *str, char charset)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_find_sep(str[i + 1], charset) == 1 && \
				ft_find_sep(str[i], charset) == 0))
			words++;
		i++;
	}
	return (words);
}

static void	ft_copy_word(char *dest, char *from, char charset)
{
	int		i;

	i = 0;
	while (ft_find_sep(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static char	**ft_transfert_to_tab(char **tab, char *str, char charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_find_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_find_sep(str[i + j], charset) == 0)
				j++;
			tab[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!tab[word])
				return (NULL);
			ft_copy_word(tab[word], str + i, charset);
			i = i + j;
			word++;
		}
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word;
	int		i;

	if (!s)
		return (NULL);
	word = ft_count_numb_of_word((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	if (tab == NULL)
		return (NULL);
	tab[word] = 0;
	if (!ft_transfert_to_tab(tab, (char *)s, c))
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	return (tab);
}
