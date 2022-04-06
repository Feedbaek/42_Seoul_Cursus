/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:23:01 by sungmcho          #+#    #+#             */
/*   Updated: 2022/03/30 17:13:33 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*one_ret_null(char **s)
{
	free(*s);
	return (NULL);
}

char	**d_ret_null(char ***s)
{
	char	**tmp;

	tmp = *s;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(tmp);
	return (NULL);
}

void	malloc_error(void)
{
	printf("malloc error");
	exit(1);
}
