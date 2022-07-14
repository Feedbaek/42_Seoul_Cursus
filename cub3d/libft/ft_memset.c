/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:45:00 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:19:55 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = dest;
	while (i < len)
		str[i++] = (unsigned char)c;
	return (dest);
}
