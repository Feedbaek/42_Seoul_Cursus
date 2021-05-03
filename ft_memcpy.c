/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:14:28 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/03 22:23:07 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	char	*tmp;
	const char *s = src;

	tmp = (char *)dest;
	if (!n || dest == src)
		return (dest);
	if (dest == 0 && src == 0)
		return (0);
	while (n--)
		*tmp++ = *s++;
	return (dest);
}
