/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:24:10 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/08 21:53:30 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*parser;

	if (!lst || !new)
		return ;
	parser = *lst;
	if (!parser)
	{
		*lst = new;
		return ;
	}
	while (parser->next)
		parser = parser->next;
	parser->next = new;
}
