/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:32:44 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/08 22:08:27 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	rec_free(t_list *lst, void (*del)(void *))
{
	if (lst->next)
		rec_free(lst->next, del);
	ft_lstdelone(lst, del);
}

void			ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del || !*lst)
		return ;
	rec_free(*lst, del);
	*lst = 0;
}
