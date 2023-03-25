/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:11:46 by minskim2          #+#    #+#             */
/*   Updated: 2021/03/30 19:15:19 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_nbr(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (!is_nbr(*str))
			return (0);
		str++;
	}
	return (1);
}
