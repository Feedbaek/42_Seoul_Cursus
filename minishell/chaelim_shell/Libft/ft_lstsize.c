/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyeon <donghyeon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:04:27 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/07 20:04:28 by donghyeon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		size;

	p = lst;
	size = 0;
	while (p != NULL)
	{
		size++;
		p = p->next;
	}
	return (size);
}
