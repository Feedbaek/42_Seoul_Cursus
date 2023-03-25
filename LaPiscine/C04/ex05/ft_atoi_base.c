/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:43:53 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/05 17:30:50 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			g_size;

int		error(char *base)
{
	int		i;

	if (g_size <= 1)
		return (1);
	while (*base)
	{
		if (*base == '+' || *base == '-' || *base == ' '
				|| (*base >= '\t' && *base <= '\r'))
			return (1);
		i = 1;
		while (base[i])
		{
			if (*base == base[i])
				return (1);
			i++;
		}
		base++;
	}
	return (0);
}

int		cal(char c, char *base)
{
	int		i;

	i = 0;
	while (i < g_size)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_putnbr_base(char *base)
{
	int		i;

	i = 0;
	g_size = 0;
	while (base[i])
	{
		g_size++;
		i++;
	}
	if (error(base))
		return (1);
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int		res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	if (ft_putnbr_base(base))
		return (0);
	while (*str)
	{
		i = cal(*str, base);
		if (i == -1)
			break ;
		res *= g_size;
		res += (sign * i);
		str++;
	}
	return (res);
}
