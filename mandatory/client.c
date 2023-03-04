/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:01:31 by bede-car          #+#    #+#             */
/*   Updated: 2023/03/04 14:25:16 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void    checking_parameters(int argc)
{
    if(argc !=3)
    {
        ft_printf("\n>> Invalid parameters, Try again! <<\n\n");
        ft_printf("Example of usage: ./client PID message\n");
        ft_printf("[1]For PID, type exacly the number of the target server\n");
        ft_printf("[2]For the message, if it has more than 1 word,");
        ft_printf("type inside parentheses\n\n");       
        exit(EXIT_FAILURE);
    }
    exit(SUCCESS);
}

int main(int argc, char **argv)
{
    checking_parameters(argc);
    t_data data;
    data.message = argv[2];
    ft_printf("%s", data.message);
     return(0);
}