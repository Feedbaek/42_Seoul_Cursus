/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:58:47 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/07 22:11:26 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_len(int n)
{
	long long	nbr;
	int			cnt;

	nbr = (long long)n;
	cnt = 0;
	if (nbr == 0)
		cnt = 1;
	else if (nbr < 0)
	{
		nbr = -nbr;
		cnt = 1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		cnt++;
	}
	return (cnt);
}

void	check3(int *n, int *flag, long long *nbr)
{
	if (*n >= 0)
	{
		*flag = 0;
		*nbr = (long long)*n;
	}
	else
	{
		*flag = 1;
		*nbr = -(long long)*n;
	}
}

char	*ft_itoa(int n)
{
	long long	nbr;
	char		*str;
	int			n_len;
	int			flag;

	n_len = ft_num_len(n);
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[n_len] = '\0';
	check3(&n, &flag, &nbr);
	n_len = n_len - 1;
	while (n_len >= flag)
	{
		str[n_len] = nbr % 10 + '0';
		nbr /= 10;
		n_len--;
	}
	return (str);
}
