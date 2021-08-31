/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:31 by minskim2          #+#    #+#             */
/*   Updated: 2021/08/31 19:43:49 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_inform
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	r;
}	t_inform;

typedef struct s_predict
{
	int	ra;
	int	rb;
	int	cnt_a;
	int	cnt_b;
	int	cnt_sum;
}	t_predict;

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	error_push_swap(char *error);
void	ft_putstr(char *str);

int		cnt_word(char *str, char c);
char	**ft_split(char *str, char c);

void	init_stack(t_inform *inform, int argc, char *argv[]);

void	quick_a(t_inform *inform, int size);
void	quick_b(t_inform *inform, int size);

void	real_quick_sort(int *stack, int left, int right);
int		find_pivot(t_inform *inform, int size);

int		is_sorted(int *stack, int n);
int		sorted_num(int *stack, int i, int size);
void	sort_5(t_inform *inform, int len);
void	sort_2_3(t_inform *inform);

void	push_to_a(t_inform *inform);
void	push_to_b(t_inform *inform, int len);

void	pa(t_inform *inform);
void	pb(t_inform *inform);
void	sa(t_inform *inform);
void	sb(t_inform *inform);
void	ss(t_inform *inform);
void	ra(t_inform *inform);
void	rb(t_inform *inform);
void	rr(t_inform *inform);
void	rra(t_inform *inform);
void	rrb(t_inform *inform);
void	rrr(t_inform *inform);

void	test(t_inform *inform);

#endif
