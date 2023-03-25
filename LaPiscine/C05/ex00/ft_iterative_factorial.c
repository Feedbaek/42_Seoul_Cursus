/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:01:48 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/05 22:08:48 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;

	i = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		i *= nb;
		nb--;
	}
	return (i);
}
