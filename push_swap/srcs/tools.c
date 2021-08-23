/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:48:37 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/23 21:27:10 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*s;

	s = (unsigned char*)src;
	tmp = (unsigned char*)dest;
	if (!n || dest == src)
		return (dest);
	while (n--)
		*tmp++ = *s++;
	return (dest);
}

int	ft_atoi(const char *str)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	while (*str == '\t'
			|| *str == ' '
			|| *str == '\n'
			|| *str == '\f'
			|| *str == '\v'
			|| *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		i *= 10;
		i += *str - '0';
		str++;
	}
	return (sign * i);
}

static int		cnt_size(int n)
{
	int size;

	size = 1;
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		if (n)
			size++;
	}
	return (size);
}

static void		iterative_sum(char *str, int n, int idx)
{
	while (n)
	{
		str[idx--] = n % 10 + '0';
		n /= 10;
	}
}

char			*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = cnt_size(n);
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	if (n < 0)
	{
		if (-(n / 10))
			iterative_sum(str, -(n / 10), size - 2);
		str[size - 1] = (unsigned char)('0' - (n % 10));
		str[0] = '-';
	}
	else
	{
		if (n / 10)
			iterative_sum(str, n / 10, size - 2);
		str[size - 1] = (unsigned char)('0' + (n % 10));
	}
	str[size] = 0;
	return (str);
}
