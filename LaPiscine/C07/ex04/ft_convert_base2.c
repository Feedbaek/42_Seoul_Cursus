/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:08:30 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/13 19:18:58 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_white(char c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

int		is_valid(char *base, int *len)
{
	int		chk[256];
	int		i;
	char	c;

	i = 0;
	while(i < 256)
		chk[i++] = 0;
	*len = 0;
	while (base[*len])
	{
		c = base[*len];
		if (chk[(int)c] || c == '+' || c == '-' || ft_is_white(c))
			return (0);
		chk[(int)c] = 1;
		++*len;
	}
	if (*len <= 1)
		return (0);
	return (1);
}

int		nbr_size(long long nbr, int base_len)
{
	int	ret;

	if (!nbr)
		return (1);
	ret = 0;
	if (nbr < 0)
		ret++;
	while (nbr)
	{
		nbr /= base_len;
		++ret;
	}
	return (ret);
}
