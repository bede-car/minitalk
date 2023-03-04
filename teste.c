/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:36:25 by bede-car          #+#    #+#             */
/*   Updated: 2023/03/04 08:02:00 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// int main(void)
// {
//   for (;;)
//     printf("Teste...\n");
//   return 0;
// }
// com control c para o loop

// #include <stdio.h>
// #include <signal.h>
// int main(void)
// {
//   signal(SIGINT, SIG_IGN);
//   for (;;)
//     printf("Teste...\n");
//   return 0;
// }
// com control c não para o loop,
// ou seja ignora entrada de comando pelo terminal

#include <sys/types.h>  /* Type definitions used by many programs */
#include <stdio.h>      /* Standard I/O functions */
#include <stdlib.h>     /* Prototypes of commonly used library functions,
                          plus EXIT_SUCCESS and EXIT_FAILURE constants */
#include <unistd.h>     /* Prototypes for many system calls */
#include <errno.h>      /* Declares errno and defines error constants */
#include <string.h>     /* Commonly used string-handling functions */
#include <stdbool.h>
#include <signal.h>
// #include <tlpi_hdr.h>

void errExit(const char *format);

static void sigHandler(int sig)
{
 printf("Ouch!\n"); /* UNSAFE (see Section 21.1.2) */
}

int main(int argc, char *argv[])
{
 int j;
    if (signal(SIGINT, sigHandler) == SIG_ERR)
         errExit("signal");

    for (j = 0; ; j++) {
        printf("%d\n", j);
        sleep(3); /* Loop slowly... */
 }
}