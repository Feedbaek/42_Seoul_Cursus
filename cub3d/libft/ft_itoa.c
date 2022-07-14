/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:43:30 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:19:24 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		pos;
	long	nbr;

	nbr = n;
	pos = 1;
	len = ft_intlen(nbr);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		pos = -1;
		nbr = -nbr;
	}
	while (len)
	{
		str[--len] = '0' + (nbr % 10);
		nbr = nbr / 10;
	}
	if (pos == -1)
		str[0] = '-';
	return (str);
}
