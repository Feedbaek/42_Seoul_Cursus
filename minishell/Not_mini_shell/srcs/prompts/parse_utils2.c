/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:17:37 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/03 16:17:42 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static size_t	count_word(char *s, char c)
{
	size_t	count;
	int		i;
	bool	quote;
	bool	dquote;

	quote = false;
	dquote = false;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (c != s[i] && (i == 0 || c == s[i - 1]) && !quote && !dquote)
			count++;
		if (s[i] == '\'' && !dquote)
			quote = !quote;
		else if (s[i] == '\"' && !quote)
			dquote = !dquote;
		i++;
	}
	if (quote || dquote)
		return (-1);
	return (count);
}

static void	make_word(int len, char **result, char *s)
{
	char	*arr;

	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		malloc_error();
	*result = arr;
	while (len)
		*arr++ = *(s - len--);
	*arr = 0;
}

static void	make_array(char **result, char *s, char c, size_t word_total)
{
	size_t	len;
	bool	quote[2];

	quote[0] = false;
	quote[1] = false;
	while (word_total--)
	{
		while (*s && c == *s)
			s++;
		len = 0;
		while (*s && (c != *s || quote[0] || quote[1]))
		{
			if (*s == '\'' && !quote[1])
				quote[0] = !quote[0];
			else if (*s == '\"' && !quote[0])
				quote[1] = !quote[1];
			s++;
			len++;
		}
		make_word(len, result, s);
		result++;
	}
}

char	**parse_split(char const *s, char c)
{
	char	**result;
	int		word_total;
	int		pos;

	word_total = count_word((char *)s, c);
	if (word_total == -1)
		return (0);
	result = (char **)malloc((word_total + 1) * sizeof(char *));
	if (!result)
		malloc_error();
	pos = 0;
	while (pos < word_total + 1)
		result[pos++] = 0;
	make_array(result, (char *)s, c, word_total);
	return (result);
}
