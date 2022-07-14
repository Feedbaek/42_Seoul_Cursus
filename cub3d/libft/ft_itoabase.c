/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:43:38 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:09:15 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long n, int base)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

static char	*ft_getbaseset(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	else
		return (NULL);
}

char	*ft_itoabase(long nbr, char type)
{
	char	*baseset;
	int		base;
	char	*str;
	int		len;

	baseset = ft_getbaseset(type);
	base = ft_strlen(baseset);
	len = ft_nbrlen(nbr, base);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len)
	{
		str[--len] = baseset[nbr % base];
		nbr = nbr / base;
	}
	return (str);
}
