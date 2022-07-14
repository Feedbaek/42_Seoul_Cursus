/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:44:45 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:19:50 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t			i;
	unsigned char	*uc_b1;
	unsigned char	*uc_b2;

	i = 0;
	uc_b1 = (unsigned char *)b1;
	uc_b2 = (unsigned char *)b2;
	while (i < len)
	{
		if (uc_b1[i] != uc_b2[i])
			return (uc_b1[i] - uc_b2[i]);
		i++;
	}
	return (0);
}
