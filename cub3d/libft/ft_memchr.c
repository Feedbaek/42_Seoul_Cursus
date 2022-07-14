/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:44:40 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:19:48 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*uc_b;

	i = 0;
	uc_b = (unsigned char *)b;
	while (i < len)
	{
		if (uc_b[i] == (unsigned char)c)
			return ((void *)&uc_b[i]);
		i++;
	}
	return (NULL);
}
