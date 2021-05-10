/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:58:15 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/10 20:26:57 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		rec_free(t_list *lst)
{
	if (!lst)
		return ;
	rec_free(lst->next);
	free(lst->content);
	free(lst);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_next;
	t_list	*parser;

	if (!lst || !f || !(new = ft_lstnew(f(lst->content))))
		return (0);
	parser = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new_next = ft_lstnew(f(lst->content))))
		{
			if (!del)
			{
				rec_free(new);
				return (0);
			}
			ft_lstclear(&new, del);
			return (0);
		}
		parser->next = new_next;
		parser = parser->next;
		lst = lst->next;
	}
	return (new);
}
