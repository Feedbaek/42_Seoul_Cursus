/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:31 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/09 17:55:23 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <get_next_line.h>

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

int		ft_atoi(const char *str);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	error_push_swap(char *error);
void	ft_putstr(char *str);

int		cnt_word(char *str, char c);
char	**ft_split(char *str, char c);

void	init_stack(t_inform *inform, int argc, char *argv[]);

void	quick_a(t_inform *inform, int size);
void	quick_b(t_inform *inform, int size);

void	real_quick_sort(int *stack, int left, int right);
int		find_pivot(int *stack, int size);

int		is_sorted(int *stack, int n);
int		sorted_num(int *stack, int i, int size);
void	sort_5(t_inform *inform, int len);
void	sort_2_3(t_inform *inform);

void	push_to_a(t_inform *inform);
void	push_to_b(t_inform *inform, int len);

void	quick_a(t_inform *inform, int size);
void	quick_b(t_inform *inform, int size);
void	sort_end(t_inform *inform);
void	sort_start(t_inform *inform);

void	init_predict(t_predict *predict);
int		find_min(int *stack, int size, int *idx);
void	find_instruction(t_inform *inform, t_predict *predict);
void	cnt_instruction(t_inform *inform, t_predict *predict, int i, int j);
void	run_instruction(t_inform *inform, t_predict *predict);
int		find_min(int *stack, int size, int *idx);
int		find_long_section(t_inform *inform);

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
