/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 23:42:01 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/02 00:26:28 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			while (str[i] && to_find[i])
			{
				if (str[i] != to_find[i])
				{
					i = 0;
					break ;
				}
				i++;
			}
			if (to_find[i] == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
