/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:46:49 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/03 22:34:36 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *dest, int fillchar, unsigned int len)
{
	unsigned int	i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char*)dest;
	while (i < len)
		temp[i++] = (unsigned char)fillchar;
	return (temp);
}
