/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:16:47 by chalim            #+#    #+#             */
/*   Updated: 2021/08/07 22:19:45 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_malloc_error(void)
{
	ft_putendl_fd("Unfortunately our malloc fails", STDERR);
	exit(1);
}

void	print_exec_error_3(char *str1, char *str2, char *str3)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(str1, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(str2, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putendl_fd(str3, STDERR);
}

void	print_exec_error_2(char *str1, char *str2)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(str1, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putendl_fd(str2, STDERR);
}

void	print_exec_error_1(char *str1)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putendl_fd(str1, STDERR);
}
