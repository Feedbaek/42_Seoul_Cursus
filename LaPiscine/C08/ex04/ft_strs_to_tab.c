/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:57:06 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/10 21:49:23 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					cntsize(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void				*strcpy(char *dest, char *src)
{
	int			i;

	i = 0;
	while (src[i])
		dest[i++] = src[i];
	dest[i] = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str	*ret;

	ret = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!ret)
		return (ret);
	i = 0;
	while (i < ac)
	{
		ret[i].size = cntsize(av[i]);
		ret[i].str = malloc(ret[i].size + 1);
		strcpy(ret[i].str, av[i]);
		ret[i].copy = malloc(ret[i].size + 1);
		strcpy(ret[i].copy, av[i]);
		i++;
	}
	ret[i].str = 0;
	return (ret);
}
