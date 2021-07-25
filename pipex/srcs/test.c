/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:31:14 by minskim2          #+#    #+#             */
/*   Updated: 2021/07/25 03:25:37 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_cmd	x;

	if (!path_finder(envp, &x))
		return (0);
	while (*x.path)
		printf("%s\n", *(x.path++));
	return (0);
}
