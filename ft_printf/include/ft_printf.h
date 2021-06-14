/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:03:06 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/14 19:33:13 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	int zero; //0
	int left; //0
	int width; //0
	int dot; //0
	int precision; // -1
	int type;
	int step;
}				t_format;

int		ft_isdigit(int c);
int		ft_atoi(const char *str);

int		ft_printf(const char *str, ...);

#endif
