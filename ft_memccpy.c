/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:20:12 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/03 21:39:53 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memccpy(void *dest, const void *src, int c, unsigned int n)
{
	char	*tmp;
	unsigned int	i;
	const char	*s = src;

	i = 0;
	if (!n && !dest)
		return ((void *)0);
	while (i < n)
	{
		tmp[i] = s[i];
		if ((unsigned char)c == *s)
			break ;
		i++;
	}
	if (n == i)
		return ((void *)0);
	return (dest + i + 1);
}
