/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:13:57 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/06 22:37:17 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		sqr(int nb)
{
	long long	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

int		ft_is_prime(int nb)
{
	int			i;
	int			sq;

	i = 2;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	sq = sqr(nb);
	while (i <= sq)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
