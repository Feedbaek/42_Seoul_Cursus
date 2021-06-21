/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:40:42 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/21 20:44:27 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	printf("===========start============\n");
	printf("==========integer===========\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%00004d|\n", 6) - 16);
	printf("출력 수: %d\n", printf("real printf: |%00004d|\n", 6) - 16);

	printf("=========unsigned int=======\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%06u|\n", 4294967295) - 16);
	printf("출력 수: %d\n", printf("real printf: |%06u|\n", (unsigned int)4294967295) - 16);

	printf("============char============\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%-4.c|\n", 0) - 16);
	printf("출력 수: %d\n", printf("real printf: |%-4.c|\n", 0) - 16);

	printf("=============str============\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%.003s|\n", "hi") - 16);
	printf("출력 수: %d\n", printf("real printf: |%.003s|\n",  "hi") - 16);

	printf("=============per============\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%%|\n") - 16);
	printf("출력 수: %d\n", printf("real printf: |%%|\n") - 16);

	printf("==============x=============\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%010x|\n", -1) - 16);
	printf("출력 수: %d\n", printf("real printf: |%010x|\n", -1) - 16);

	printf("==============xl============\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%010X|\n", -1) - 16);
	printf("출력 수: %d\n", printf("real printf: |%010X|\n", -1) - 16);

	printf("=============adr============\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%*p%-135.109d|\n",-15,(void*)15603137398285451084lu,1482420587) - 16);
	printf("출력 수: %d\n", printf("real printf: |%*p%-135.109d|\n",-15,(void*)15603137398285451084lu,1482420587) - 16);

	printf("============end=============\n");
	return (0);
}
