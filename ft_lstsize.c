/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:15:57 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/08 21:37:46 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*parser;
	int		size;

	if (!lst)
		return (0);
	size = 0;
	parser = lst;
	while (parser)
	{
		parser = parser->next;
		size++;
	}
	return (size);
}
