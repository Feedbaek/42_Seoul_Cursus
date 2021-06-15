/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:03:06 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/15 20:55:20 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_format
{
	int zero; //0
	int left; //0
	int width; //0
	int dot; //0
	int precision; // -1
	int type;
	int step;
	int value;
}				t_format;

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);

char	*ft_itoa(int n);

int		check_dot(const char *str, t_format *form);
int		check_flag(const char *str, t_format *form);
int		check_width(const char *str, t_format *form, va_list ap);
int		check_precision(const char *str, t_format *form, va_list ap);
int		check_type(const char *str, t_format *form);

int		int_print(const char *str, t_format *form, int i);
int		unint_print(const char *str, t_format *form, int i);

int		char_print(const char *str, t_format *form, int i);
int		str_print(const char *str, t_format *form, int i);
int		percent_print(const char *str, t_format *form, int i);

int		x_print(const char *str, t_format *form, int i);
int		xl_print(const char *str, t_format *form, int i);
int		addr_print(const char *str, t_format *form, int i);

int		ft_printf(const char *str, ...);

#endif
