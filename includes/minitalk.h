/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:06:22 by bede-car          #+#    #+#             */
/*   Updated: 2023/03/04 13:28:54 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include "../libftprintf/source/ft_printf.h"

//#define SIGUSR1 0
//#define SIGUSR2 1
#define SUCCESS EXIT_SUCCESS 
#define ERROR EXIT_FAILURE 

typedef struct s_minitalk
{
    int     pid;
    char    *message;
}   t_data;

// int main(void);

#endif