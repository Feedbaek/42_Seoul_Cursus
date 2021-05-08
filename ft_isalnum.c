/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:26:40 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/07 22:29:23 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	if (c > 255)
		return (0);
	if (((unsigned char)c >= '0' && (unsigned char)c <= '9')
		|| ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
		|| ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z'))
		return (1);
	return (0);
}
