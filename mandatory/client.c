/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:01:31 by bede-car          #+#    #+#             */
/*   Updated: 2023/03/05 23:04:31 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_bit(int pid, char *message)
{
	static int	backup_pid;
	static char *backup_message;
	static int	bit;
	static int	index;

	if (!backup_message)
		backup_message = message;
	if (backup_pid == 0)
		backup_pid = pid;
	if ((message[index] >> bit++ & 1) == 1)
	{
		kill(backup_pid, SIGUSR1);
	}
	else
		kill(backup_pid, SIGUSR2);
	if (bit == 7)
	{
		bit = 0;
		index++;
	}
	usleep(300);
}

void	signal_sender(int signal, siginfo_t *info, void *ucontext)
{
	if (signal == SIGUSR1)
		send_bit(info->si_pid, (char*)ucontext);
	else
		exit(SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	client;
	struct sigaction	client_action;

	client.pid = 0;

	sigemptyset(&client_action.sa_mask);
    client_action.sa_flags = SA_SIGINFO;
    client_action.sa_sigaction = signal_sender;
	input_client_validation(argc, argv, &client);
	if (sigaction(SIGUSR1, &client_action, NULL))
		ft_printf("Failed to use sigaction on signal SIGUSR1.\n");
	if (sigaction(SIGUSR2, &client_action, NULL))
		ft_printf("Failed to use sigaction on signal SIGUSR2.\n");
	send_bit(client.pid, client.message);
	while(1)
		pause();
	return (0);
}
