/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:20:23 by minskim2          #+#    #+#             */
/*   Updated: 2021/03/30 22:37:55 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int		ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (!is_printable(*str))
			return (0);
		str++;
	}
	return (1);
}
