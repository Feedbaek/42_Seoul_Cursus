/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:21:54 by minskim2          #+#    #+#             */
/*   Updated: 2021/03/30 19:27:54 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int		ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (!is_lower(*str))
			return (0);
		str++;
	}
	return (1);
}
