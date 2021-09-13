/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:42:31 by minskim2          #+#    #+#             */
/*   Updated: 2021/09/13 21:36:21 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <get_next_line.h>

typedef struct s_inform
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	r;
	int	checker;
}	t_inform;

typedef struct s_param
{
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pa;
	int	cnt_pb;
	int	cnt_skip;
	int	check_rr;
	int	big_pivot;
	int	small_pivot;
}	t_param;

int		ft_atoi(const char *str);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	error_push_swap(char *error);
void	ft_putstr(char *str);

int		cnt_word(char *str, char c);
char	**ft_split(char *str, char c);

void	init_stack(t_inform *inform, int argc, char *argv[]);

void	real_quick_sort(int *stack, int left, int right);
int		find_pivot(int *stack, int size);
void	find_pivot_2(int *stack, int size, int *big_pivot, int *small_pivot);

int		is_sorted(int *stack, int n, int opt);

void	a_to_b(t_inform *inform, int size);
void	first_a_to_b(t_inform *inform, int size);
void	b_to_a(t_inform *inform, int size);

int		set_a_to_b(t_inform *inform, t_param *param, int size);
void	a_to_b_init_cnt(t_param *param);
int		a_to_b_check_pivot(t_inform *inform, int pivot, int size);
void	a_to_b_sort_3(t_inform *inform);
void	a_to_b_call_rrr(t_inform *inform, int cnt_ra, int cnt_rb);

int		set_b_to_a(t_inform *inform, t_param *param, int size);
void	b_to_a_init_cnt(t_param *param);
int		b_to_a_check_pivot(t_inform *inform, int pivot, int size);
void	b_to_a_sort_3(t_inform *inform);
void	b_to_a_call_rrr(t_inform *inform, int cnt_ra, int cnt_rb);

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

#endif
