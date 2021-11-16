/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chalim <42.4.chalim@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 04:40:26 by donghyeon         #+#    #+#             */
/*   Updated: 2021/08/08 19:38:39 by chalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_state	g_state;

void	ascii_art1(void)
{
	ft_putstr_fd("	 _   .-')                 .-') _       ", 1);
	ft_putendl_fd("   .-')    ('-. .-.   ('-.                    ", 1);
	ft_putstr_fd("( '.( OO )_              ( OO ) )        ", 1);
	ft_putendl_fd("( OO ). ( OO )  / _(  OO)                    ", 1);
	ft_putstr_fd(" ,--.   ,--.) ,-.-') ,--./ ,--,' ,-.-') (", 1);
	ft_putendl_fd("_)---\\_),--. ,--.(,------.,--.      ,--.     ", 1);
	ft_putstr_fd(" |   `.'   |  |  |OO)|   \\ |  |\\ |  |OO", 1);
	ft_putendl_fd(")/    _ | |  | |  | |  .---'|  |.-')  |  |.-') ", 1);
	ft_putstr_fd(" |         |  |  |  \\|    \\|  | )|  |  ", 1);
	ft_putendl_fd("\\  :` `. |   .|  | |  |    |  | OO ) |  | OO )", 1);
	ft_putstr_fd(" |  |'.'|  |  |  |(_/|  .     |/ |  |(_/ ", 1);
	ft_putendl_fd("'..`''.)|       |(|  '--. |  |`-' | |  |`-' |", 1);
	ft_putstr_fd(" |  |   |  | ,|  |_.'|  |\\    | ,|  |_.'", 1);
	ft_putendl_fd(".-._)   \\|  .-.  | |  .--'(|  '---.'(|  '---.'", 1);
	ft_putstr_fd(" |  |   |  |(_|  |   |  | \\   |(_|  |   ", 1);
	ft_putendl_fd("\\       /|  | |  | |  `---.|      |  |      | ", 1);
	ft_putstr_fd(" `--'   `--'  `--'   `--'  `--'  `--'    ", 1);
	ft_putendl_fd("`-----' `--' `--' `------'`------'  `------' ", 1);
}

void	ascii_art2(void)
{
	ft_putendl_fd("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀ ", 1);
	ft_putendl_fd("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠋⠀⠈⠹⣿⣿⣿⣿⣦⣀⠀⠀ ", 1);
	ft_putendl_fd("⠀⠀⢿⣷⣶⣤⣀⣀⣼⡏⠀⠀⡀⠀⠸⣿⣿⣿⣿⠿⡷⠀ ", 1);
	ft_putendl_fd("⠀⠀⠘⣿⣿⣿⣿⣿⣿⡇⠀⠀⠉⠉⣠⣴⣮⣩⣤⠄⢰⠀ ", 1);
	ft_putendl_fd("⠀⠀⠀⠘⢿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣷⣾⠀ ", 1);
	ft_putendl_fd("⠀⠀⠀⠀⠈⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠘⠿⣿⣿⣿⣿⡇ ", 1);
	ft_putendl_fd("⠀⠀⠀⠀⢰⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⣿⡇ ", 1);
	ft_putendl_fd("⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇ ", 1);
	ft_putendl_fd("⠀⠀⠀⠀⠘⢤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡸⠁ ", 1);
	ft_putendl_fd("⠀⠀⠀⠚⠿⠿⣿⡶⠤⢀⣀⣀⣀⣀⣀⣀⣀⣀⣤⣮⣄⠀ ", 1);
	ft_putendl_fd("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠛⠉⠁⠀ ", 1);
}

void	prepare_token_and_cmd(t_state *state)
{
	free(state->input);
	state->input = 0;
	free(state->input2);
	state->input2 = 0;
	reset_save(state);
}

void	init_state(t_state *state)
{
	ft_memset((void *)state, 0, sizeof(t_state));
	tcgetattr(0, &state->t.save);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	cmd_list;

	(void)argv;
	(void)argc;
	ascii_art2();
	ascii_art1();
	init_state(&g_state);
	signal(SIGINT, (void *)handle_signal);
	signal(SIGQUIT, (void *)handle_signal);
	set_env_export(envp);
	while (1)
	{
		prompt2(&g_state);
		tcsetattr(0, TCSANOW, &g_state.t.save);
		if (!parse_pipe(g_state.input, &cmd_list))
			exec_start(&cmd_list);
		prepare_token_and_cmd(&g_state);
	}
	return (g_state.exit_status & 255);
}
