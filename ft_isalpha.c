/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:09:05 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/07 22:29:23 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	if (c > 255)
		return (0);
	if (((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
		|| ((unsigned char)c >= 'a' && (unsigned char)c <= 'z'))
		return (1);
	return (0);
}
