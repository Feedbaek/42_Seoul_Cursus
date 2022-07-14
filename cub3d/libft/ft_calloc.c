/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:42:26 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:07:26 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*mem;

	mem = malloc(number * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (number * size));
	return (mem);
}
