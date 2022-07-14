/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:42:33 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:18:57 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_cntword(char const *s, char c)
{
	size_t		count;
	int			word_start;

	count = 0;
	word_start = 1;
	while (*s)
	{
		if (*s == c)
			word_start = 1;
		else if (word_start == 1)
		{
			count++;
			word_start = 0;
		}
		s++;
	}
	return (count);
}
