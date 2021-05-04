/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:01:23 by minskim2          #+#    #+#             */
/*   Updated: 2021/05/04 23:02:47 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int				ft_atoi(char *str);
void			ft_bzero(void *s, unsigned int n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dest, const void *src, int c, unsigned int n);
int				ft_memcmp(const void *dest, const void *src, unsigned int num);
void			*ft_memchr(const void *ptr, int value, unsigned int num);
void			*ft_memcpy(void *dest, const void *src, unsigned int n);
void			*ft_memmove(void *dest, const void *src, unsigned int n);
void			*ft_memset(void *dest, int fillchar, unsigned int len);
char			*ft_strchr(const char *str, int c);
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);
int				ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_strnstr(const char *str, const char *substr,
							unsigned int len);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strlcpy(char *dest, const char *src, unsigned int size);

#endif
