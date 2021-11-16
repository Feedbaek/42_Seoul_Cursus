/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 07:59:33 by chalim            #+#    #+#             */
/*   Updated: 2021/08/07 22:19:31 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*result;
	size_t	total;
	size_t	i;

	total = 0;
	i = 0;
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		print_malloc_error();
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	total = i;
	i = 0;
	while (s2[i])
	{
		result[total + i] = s2[i];
		i++;
	}
	result[total + i] = 0;
	free(s1);
	free(s2);
	return (result);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*result;
	size_t	total;
	size_t	i;

	total = 0;
	i = 0;
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		print_malloc_error();
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	total = i;
	i = 0;
	while (s2[i])
	{
		result[total + i] = s2[i];
		i++;
	}
	result[total + i] = 0;
	free(s1);
	return (result);
}
