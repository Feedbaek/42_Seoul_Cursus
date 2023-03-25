/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:04:33 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/01 17:35:35 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	is_alpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

char	*ft_strlowcase(char *str)
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
