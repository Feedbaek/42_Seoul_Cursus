/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyeon <donghyeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:23:31 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/07 20:24:18 by donghyeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_str_copy(char *s1, char *result, int start, int end)
{
	int		i;

	i = 0;
	while (s1[start + i] && start + i <= end)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static int	ft_find_start_index(int i, char *s1, char *set)
{
	int		j;

	while (s1[i])
	{
		j = 0;
		while (set[j] && s1[i] != set[j])
			j++;
		if (set[j] == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_find_end_index(int k, char *s1, char *set)
{
	int		j;

	while (s1[k] && k > 0)
	{
		j = 0;
		while (set[j] && s1[k] != set[j])
			j++;
		if (set[j] == 0)
			break ;
		if (k == 0)
			break ;
		k--;
	}
	return (k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;

	if (s1 == 0)
		return (ft_strdup(""));
	start = ft_find_start_index(0, (char *)s1, (char *)set);
	end = ft_find_end_index(ft_strlen((char *)s1) - 1, (char *)s1, (char *)set);
	if (start == (int)ft_strlen((char *)s1) || end == 0)
		return (ft_strdup(""));
	result = (char *)malloc((end - start + 1 + 1) * sizeof(char));
	if (!result)
		return (ft_strdup(""));
	return (ft_str_copy((char *)s1, result, start, end));
}
