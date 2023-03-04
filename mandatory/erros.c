/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:03:22 by bede-car          #+#    #+#             */
/*   Updated: 2023/03/04 16:09:35 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	input_server_validation(int argc, char **argv)
{
	if (argc != 1 && argv[1])
	{
		ft_printf("\n>> Oh no! <<\n I would like to start a \"mini talk\" ");
		ft_printf("but no parameters are expected, Try again!\n\n");
		exit(EXIT_FAILURE);
	}
}

void	input_client_validation(int argc, char **argv)
{
	if (argc != 3 && argv[1])
	{
		ft_printf("\n>> Invalid parameters, Try again! <<\n\n");
		ft_printf("Example of usage: ./client PID message\n");
		ft_printf("[1]For PID, type the exacly number of the target server\n");
		ft_printf("[2]For the message, if it has more than 1 word,");
		ft_printf(" type inside parentheses ");
		ft_printf("like: \n\t \"this message is a test\"\n\n");
		exit(EXIT_FAILURE);
	}
}
