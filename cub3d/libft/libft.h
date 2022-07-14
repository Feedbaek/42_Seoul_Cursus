/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:48:27 by donghyki          #+#    #+#             */
/*   Updated: 2022/06/10 21:10:45 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void				*ft_memset(void *dest, int c, size_t len);
void				ft_bzero(void *b, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *b, int c, size_t len);
int					ft_memcmp(const void *b1, const void *b2, size_t len);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t number, size_t size);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(const char *s);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(char *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
char				*ft_itoabase(long n, char type);
char				*ft_strjoin(char *s1, const char *s2);
int					get_next_line(int fd, char **line);
void				ft_exit(const char *str);
int					ft_isformat(char *str, char *fmt);
void				ft_free2d(char **arr);
int					ft_isdigit_str(const char *str);
size_t				ft_lstmaxwidth(t_list *lst);
size_t				ft_cntword(char const *s, char c);

#endif
