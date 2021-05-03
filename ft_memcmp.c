/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:52:30 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/03 22:23:06 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_memcmp(const void *dest, const void *src, unsigned int num)
{
	unsigned int	i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	i = 0;
	temp1 = (unsigned char *)dest;
	temp1 = (unsigned char *)src;
	while (i < num)
	{
		if (temp1[i] != temp2[i])
			return (temp1[i] - temp2[i]);
		i++;
	}
	return (0);
}
