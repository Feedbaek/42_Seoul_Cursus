/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equals.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:18:13 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/03 16:18:17 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	equals(char *s1, char *s2)
{
	if (ft_strlen(s1) == ft_strlen(s2))
		if (!ft_strncmp(s1, s2, ft_strlen(s1)))
			return (1);
	return (0);
}
