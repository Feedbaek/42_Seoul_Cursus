/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmaxwidth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:44:16 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:19:42 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstmaxwidth(t_list *lst)
{
	size_t	max;
	size_t	len;

	max = 0;
	while (lst)
	{
		len = ft_strlen((const char *)lst->content);
		if (len > max)
			max = len;
		lst = lst->next;
	}
	return (max);
}
