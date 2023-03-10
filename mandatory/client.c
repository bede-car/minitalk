/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:01:31 by bede-car          #+#    #+#             */
/*   Updated: 2023/03/06 09:14:28 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	input_client_validation(int argc, char **argv, t_data *client)
{
	client->pid = ft_atoi(argv[1]);
	if (argc != 3 || client->pid <= 0)
	{
		ft_printf("\n>> Invalid parameters, Try again! <<\n\n");
		ft_printf("Example of usage: ./client PID message\n");
		ft_printf("[1]For PID, type the exacly number of the target server\n");
		ft_printf("[2]For the message, if it has more than 1 word,");
		ft_printf(" type inside parentheses ");
		ft_printf("like: \n\t \"this message is an example\"\n\n");
		exit(EXIT_FAILURE);
	}
	client->message = argv[2];
}

void	send_bit(int pid, char *message)
{
	static int	backup_pid;
	static char	*backup_message;
	static int	bit;
	static int	index;

	if (!backup_message)
		backup_message = message;
	if (!backup_pid)
		backup_pid = pid;
	if ((backup_message[index] >> bit++ & 1) == 1)
		kill(backup_pid, SIGUSR1);
	else
		kill(backup_pid, SIGUSR2);
	if (bit == 7)
	{
		bit = 0;
		index++;
	}
	usleep(100);
}

void	signal_sender(int signal, siginfo_t *info, void *ucontext)
{
	if (signal == SIGUSR1)
		send_bit(info->si_pid, (char *)ucontext);
	else
		exit(SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data				client;
	struct sigaction	client_action;

	client.pid = 0;
	sigemptyset(&client_action.sa_mask);
	client_action.sa_flags = SA_SIGINFO;
	client_action.sa_sigaction = signal_sender;
	input_client_validation(argc, argv, &client);
	if (sigaction(SIGUSR1, &client_action, NULL))
	{
		ft_printf("Failed to use sigaction on signal SIGUSR1.\n");
		exit(SUCCESS);
	}
	if (sigaction(SIGUSR2, &client_action, NULL))
	{
		ft_printf("Failed to use sigaction on signal SIGUSR2.\n");
		exit(SUCCESS);
	}
	send_bit(client.pid, client.message);
	while (1)
		pause ();
	return (0);
}
