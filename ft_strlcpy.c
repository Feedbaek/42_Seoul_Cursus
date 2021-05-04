/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:25:49 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/04 23:02:43 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	ft_strlen(const char *str)
{
	unsigned int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int					ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = ft_strlen(src);
	if (!dest || !src)
		return (0);
	while (i < len && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = 0;
	return (len);
}
