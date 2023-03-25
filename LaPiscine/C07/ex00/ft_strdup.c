/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:20:46 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/12 00:30:06 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *str)
{
	long long	len;
	char		*p;

	len = 0;
	while (str[len])
		len++;
	p = (char *)malloc(len + 1);
	p[len] = 0;
	while (--len >= 0)
		p[len] = str[len];
	return (p);
}
