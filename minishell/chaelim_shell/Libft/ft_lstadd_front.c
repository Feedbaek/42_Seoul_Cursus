/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyeon <donghyeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:59:25 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/07 19:59:26 by donghyeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == 0 || new == 0)
		return ;
	else if (*lst == 0 && new != NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
