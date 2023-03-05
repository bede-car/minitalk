/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:01:33 by bede-car          #+#    #+#             */
/*   Updated: 2023/03/05 14:07:09 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	t_data	server;

	input_server_validation(argc, argv);
	server.pid = (int)getgid();
	ft_printf("\n>> Ok let's talk! <<\n");
	ft_printf("Here is the PID: %d (use it to send a message) \n\n", server.pid);
	while (1)
		pause();
	return (SUCCESS);
}
