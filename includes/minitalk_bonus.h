/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:06:22 by bede-car          #+#    #+#             */
/*   Updated: 2023/03/06 08:20:49 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdio.h>
# include "../libftprintf/source/ft_printf.h"

# define SUCCESS EXIT_SUCCESS 
# define ERROR EXIT_FAILURE 

typedef struct s_minitalk
{
	int		pid;
	char	*message;
}	t_data;

//--------------> Functions <----------------//
void	signal_receiver(int signal, siginfo_t *info, void *ucontext);
void	input_server_validation(int argc, char **argv);
void	signal_sender(int signal, siginfo_t *info, void *ucontext);
void	send_bit(int pid, char *message);
void	input_client_validation(int argc, char **argv, t_data *client);

#endif
