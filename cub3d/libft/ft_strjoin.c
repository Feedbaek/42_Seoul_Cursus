/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:46:16 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:13:35 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (len_s1 + len_s2 + 1))
		str[i++] = 0;
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, len_s1 + len_s2 + 1);
	free(s1);
	return (str);
}
