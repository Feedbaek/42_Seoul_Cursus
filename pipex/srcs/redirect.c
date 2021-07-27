/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:21:22 by minskim2          #+#    #+#             */
/*   Updated: 2021/07/27 17:22:52 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_in(const char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd < 0)
	{
		perror(file);
		exit (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	redirect_out(const char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		exit (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
