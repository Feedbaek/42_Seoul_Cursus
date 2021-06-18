/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:03:06 by minskim2          #+#    #+#             */
/*   Updated: 2021/06/18 16:25:33 by minskim2         ###   ########.fr       */
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
int		ft_putstr_fd(char *s, int fd, t_format *form);

char	*ft_itoa(long long n);
int		flag_print(int len, t_format *form, long long value);

char	*ft_hextoa(long long n);

int		check_dot(const char *str, t_format *form);
int		check_flag(const char *str, t_format *form);
int		check_width(const char *str, t_format *form, va_list ap);
int		check_precision(const char *str, t_format *form, va_list ap);
int		check_type(const char *str);

int		int_print(t_format *form, int value);
int		unint_print(t_format *form, unsigned int value);

int		x_print(t_format *form, unsigned int value);
int		xl_print(t_format *form, unsigned int value);
int		addr_print(t_format *form, void *value);

int		char_print(t_format *form, int value);
int		str_print(t_format *form, char *value);
int		percent_print(t_format *form, int value);

int		ft_printf(const char *str, ...);

#endif
