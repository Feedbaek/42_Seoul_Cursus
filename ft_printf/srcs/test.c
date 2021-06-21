/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:40:42 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/21 21:38:17 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	printf("===========start============\n");
	printf("==========integer===========\n");
	printf("출력 수: %d\n", ft_printf("myft printf: |%*.5i|\n", 4, -42) - 16);
	printf("출력 수: %d\n", printf("real printf: |%*.5i|\n", 4, -42) - 16);

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
	printf("출력 수: %d\n", ft_printf("myft printf: |%.p|\n", (void*)0) - 16);
	printf("출력 수: %d\n", printf("real printf: |%.p|\n", (void*)0) - 16);

	printf("============end=============\n");
	return (0);
}
