/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyeon <donghyeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:00:35 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/07 20:03:24 by donghyeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*lst_curr;
	t_list	*new_curr;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new == NULL)
		return (NULL);
	new_curr = new;
	lst_curr = lst->next;
	while (lst_curr != NULL)
	{
		new_curr->next = ft_lstnew(f(lst_curr->content));
		if (new_curr->next == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		new_curr = new_curr->next;
		lst_curr = lst_curr->next;
	}
	return (new);
}
