/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:15:36 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/03 16:30:36 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *str, const char *substr, unsigned int len)
{
	unsigned int i;

	if (substr[0] == 0)
		return ((char*)str);
	while (*str != 0 && len-- > 0)
	{
		i = 0;
		while (str[i] == substr[i] && i < len)
		{
			i++;
			if (substr[i] == 0)
				return ((char *)str);
		}
		str++;
	}
	return (0);
}
