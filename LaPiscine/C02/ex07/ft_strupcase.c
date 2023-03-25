/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:44:07 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/01 17:34:26 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char	*ft_strupcase(char *str)
{
	char *adr;

	adr = str;
	while (*adr)
	{
		*adr = is_alpha(*adr);
		adr++;
	}
	return (str);
}
