/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:06:22 by bede-car          #+#    #+#             */
/*   Updated: 2023/03/05 21:24:17 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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
void	input_server_validation(int argc, char **argv);
void	input_client_validation(int argc, char **argv, t_data *client);

#endif
