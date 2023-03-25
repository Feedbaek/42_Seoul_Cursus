/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:51:51 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/01 15:37:51 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	is_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

char	is_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

void	is_capitalize(char *str)
{
	if (*str >= 'a' && *str <= 'z')
		*str -= 32;
	while (*str)
	{
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
			if (!(*str >= '0' && *str <= '9'))
				*(str + 1) = is_upper(*(str + 1));
		str++;
	}
}

char	*ft_strcapitalize(char *str)
{
	char *adr;
	char *tmp;

	adr = str;
	tmp = str;
	while (*str)
	{
		*str = is_lower(*str);
		str++;
	}
	is_capitalize(adr);
	return (tmp);
}
