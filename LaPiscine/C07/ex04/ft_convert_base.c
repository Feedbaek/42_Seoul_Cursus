/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:41:41 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/13 19:28:21 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		nbr_size(long long nbr, int base_len);
int		is_valid(char *base, int *len);
int		ft_is_white(char c);
int		atoi_c7(char *str, char *base, int base_len)
{
	int ret;
	int sign;
	int idx;

	ret = 0;
	sign = 1;
	while (ft_is_white(*str))
		++str;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (*str)
	{
		idx = -1;
		while (++idx < base_len)
		{
			if (*str == base[idx])
				break ;
		}
		if (idx == base_len)
			break ;
		ret = ret * base_len + (sign * idx);
		++str;
	}
	return (ret);
}

char	*putnbr_c7(int nbr, char *base, int base_len)
{
	long long	tmp;
	char		*ret;
	int			size;

	if (nbr == 0)
	{
		ret = (char*)malloc(2);
		ret[0] = base[0];
		ret[1] = 0;
		return (ret);
	}
	tmp = nbr;
	size = nbr_size(tmp, base_len);
	ret = (char*)malloc(size + 1);
	ret[size] = 0;
	if (tmp < 0)
		tmp *= -1;
	while (tmp)
	{
		ret[--size] = base[tmp % base_len];
		tmp /= base_len;
	}
	if (nbr < 0)
		ret[0] = '-';
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int len_f;
	int len_t;

	if (!is_valid(base_from, &len_f) || !is_valid(base_to, &len_t))
		return (0);
	return (putnbr_c7(atoi_c7(nbr, base_from, len_f), base_to, len_t));
}
