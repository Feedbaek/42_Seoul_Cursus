/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:18:54 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/03 20:41:54 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
임시 파일을 이용한 here_doc 처리
	1.	O_WRONLY, O_CREAT, O_TRUNC 모드 및 0644 권한으로 임시 파일 생성
	2.	limiter가 나오기 전까지 임시 파일에 기록
	3.	limiter를 만나면 기록을 중지하고 임시 파일을 닫기
	4.	O_RDONLY 모드로 임시 파일 다시 열기
	5.	dup2를 통해 표준 입력을 임시 파일로 돌리기
	6.	임시 파일 닫기
*/

static int	create_tmp(char *name)
{
	int	fd;

	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		printf("bash: %s: %s\n", name, strerror(errno));
		exit(1);
	}
	return (fd);
}

static char	*tmp_naming(void)
{
	int		fd;
	char	*name;
	char	*new_name;

	name = (char *)malloc(sizeof(char) * 5);
	if (!name)
		print_str_error("malloc");
	ft_strlcpy(name, "_tmp", 5);
	fd = open(name, O_RDONLY);
	while (fd > 0)
	{
		close(fd);
		new_name = ft_strjoin(name, "_tmp");
		if (!new_name)
			print_str_error("ft_strjoin");
		free(name);
		name = new_name;
		fd = open(name, O_RDONLY);
	}
	if (errno != ENOENT)
	{
		printf("bash: %s: %s\n", name, strerror(errno));
		exit(1);
	}
	return (name);
}

static void	run_here_doc(t_cmd *cmd_arg)
{
	int		fd;
	int		status;
	char	*buff;

	cmd_arg->tmp = tmp_naming();
	fd = create_tmp(cmd_arg->tmp);
	write(1, "> ", 2);
	status = get_next_line(0, &buff);
	if (status < 0)
		print_str_error("get_next_line");
	while (!equals(buff, cmd_arg->limiter))
	{
		if (!status)
			break ;
		if (write(fd, buff, ft_strlen(buff)) < 0 || write(fd, "\n", 1) < 0)
			print_str_error("write");
		free(buff);
		write(1, "> ", 2);
		status = get_next_line(0, &buff);
		if (status < 0)
			print_str_error("get_next_line");
	}
	free(buff);
	close(fd);
}

void	here_doc(t_cmd *cmd_arg)
{
	echoctl_off();
	signal(SIGINT, handle_heredoc);
	while (cmd_arg)
	{
		if (cmd_arg->limiter)
			run_here_doc(cmd_arg);
		cmd_arg = cmd_arg->next;
	}
	signal(SIGINT, handle_signal);
	echoctl_on();
}
