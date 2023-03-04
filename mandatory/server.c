/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:01:33 by bede-car          #+#    #+#             */
/*   Updated: 2023/03/04 14:19:12 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int main(int argc, char **argv)
{
    if (argc != 1 && argv[1])
        {
        ft_printf("\n>> Oh no! <<\n I would like to start a \"mini talk\" ");
        ft_printf("but no parameters are expected, Try again!\n\n");       
        exit(EXIT_FAILURE);
        }
    t_data data;
    data.pid = (int)getgid();
    ft_printf("\n>> Ok let's talk! <<\n");
    ft_printf("Here is the PID: %d; use it to send a message \n\n", data.pid);
    return(SUCCESS);
}