/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 10:10:02 by minskim2          #+#    #+#             */
/*   Updated: 2021/04/15 13:36:17 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_H
# define DO_H

# include <unistd.h>

int		sum(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
void	ft_putstr(char *str);
void	rec(int nb);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

#endif
