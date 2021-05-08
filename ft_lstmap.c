/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:58:15 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/08 22:44:43 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_next;
	t_list	*parser;

	if (!lst || !f || !del)
		return (0);
	if (!(new = ft_lstnew(f(lst->content))))
		return (0);
	parser = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new_next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (0);
		}
		parser->next = new_next;
		parser = parser->next;
		lst = lst->next;
	}
	return (new);
}
