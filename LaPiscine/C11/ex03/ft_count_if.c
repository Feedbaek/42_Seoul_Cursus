/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:09:45 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/13 14:43:40 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int cnt;
	int ret;
	int i;

	cnt = 0;
	i = 0;
	while (i < length)
	{
		ret = f(tab[i]);
		if (ret != 0)
			cnt++;
		i++;
	}
	return (cnt);
}
