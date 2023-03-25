/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:41:57 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/01 21:54:14 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*origin;
	unsigned int	i;

	origin = dest;
	i = 0;
	while (*origin)
		origin++;
	while (*src && i < nb)
	{
		*origin = *src;
		origin++;
		src++;
		i++;
	}
	*origin = 0;
	return (dest);
}
