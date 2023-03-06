/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:01:33 by bede-car          #+#    #+#             */
/*   Updated: 2023/03/06 09:17:17 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	input_server_validation(int argc, char **argv)
{
	if (argc != 1 && argv[0])
	{
		ft_printf("\n>> Oh no! <<\n I would like to start a \"mini talk\" ");
		ft_printf("but no parameters are expected, Try again!\n\n");
		exit(EXIT_FAILURE);
	}
}

void	signal_receiver(int signal, siginfo_t *info, void *ucontext)
{
	static char	character;
	static int	shift;

	(void)ucontext;
	if (signal == SIGUSR1)
		character = character + (1 << shift);
	if (shift == 7)
	{
		if (!character)
		{
			ft_printf("\nmessage was recived\n");
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &character, 1);
		shift = 0;
		character = 0;
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	shift++;
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	t_data				server;
	struct sigaction	server_action;

	sigemptyset(&server_action.sa_mask);
	server_action.sa_flags = SA_SIGINFO;
	server_action.sa_sigaction = signal_receiver;
	input_server_validation(argc, argv);
	server.pid = getpid();
	ft_printf("\n>> Ok let's talk! <<\n");
	ft_printf("Here is the PID: %d (use it to send a message) \n\n", server.pid);
	if (sigaction(SIGUSR1, &server_action, NULL))
	{
		ft_printf("Failed to use sigaction on signal SIGUSR1.\n");
		exit(SUCCESS);
	}
	if (sigaction(SIGUSR2, &server_action, NULL))
	{
		ft_printf("Failed to use sigaction on signal SIGUSR2.\n");
		exit(SUCCESS);
	}
	while (1)
		pause();
	return (SUCCESS);
}
