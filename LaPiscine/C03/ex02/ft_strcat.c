/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:45:02 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/01 21:41:02 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char *origin;

	origin = dest;
	while (*origin)
		origin++;
	while (*src)
	{
		*origin = *src;
		src++;
		origin++;
	}
	*origin = 0;
	return (dest);
}
