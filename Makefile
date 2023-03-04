# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 19:57:26 by bede-car          #+#    #+#              #
#    Updated: 2023/03/04 12:35:18 by bede-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------> colors <----------------#
GREEN = \033[32m
YELLOW = \e[0;33m
BLUE = \033[34m
RESET = \033[0m

#-------------> minitalk <--------------#
NAME			=	minitalk
HEADER			=	./includes/minitalk.h
#--------------> utils <----------------#
LIB				=	./libftprintf/libftprintf.a

CFLAG			=	-Wall -Wextra -Werror -I.
MAKEFLAGS		=	--no-print-directory
RM				=	rm -f

#------------> mandatory <----------------#
PATH_MANDATORY	=	./mandatory/

#------------> bonus <----------------#
PATH_BONUS		=	./bonus/

#--------------> client <----------------#
NAME_CLIENT		=	client

SOURCE_CLIENT 	= 	client.c
OBJS_CLIENT		=	$(addprefix $(PATH_MANDATORY), $(SOURCE_CLIENT:.c=.o)) 

#--------------> server <----------------#
NAME_SERVER		=	server

SOURCE_SERVER 	=	server.c
OBJS_SERVER		=	$(addprefix $(PATH_MANDATORY), $(SOURCE_SERVER:.c=.o)) 
 

%.o:%.c ${HEADER}
	cc ${CFLAG} -c $< -o $@ 

all: libftprintf $(NAME_CLIENT) $(NAME_SERVER)
	@echo "$(BLUE)>>> Minitalk is already avalaible to run !\n $(RESET)"
	
libftprintf:
#	@echo "$(YELLOW)Compiling my own libftprintf >>>>$(RESET)"
	@make -C ./libftprintf
#	@echo "$(GREEN)libftprintf done\n $(RESET)"


$(NAME_CLIENT): $(OBJS_CLIENT) $(LIB)
	@echo "$(YELLOW)creating a client >>>>$(RESET)"
	cc  ${CFLAG} ${OBJS_CLIENT} ${LIB} -o $(NAME_CLIENT)
	@echo "$(GREEN)>>> client was created !\n $(RESET)"

$(NAME_SERVER): $(OBJS_SERVER) $(LIB)
	@echo "$(YELLOW)creating a server >>>>$(RESET)"
	cc ${CFLAG} $(OBJS_SERVER) ${LIB} -o $(NAME_SERVER)
	@echo "$(GREEN)>>> server was created !\n $(RESET)"
	
clean :
	${RM} ${OBJS_CLIENT} 
	${RM} ${OBJS_SERVER} 
	$(MAKE) clean -C ./libftprintf
	 
fclean : clean
	${RM} ${NAME_CLIENT}
	${RM} ${NAME_SERVER}
	${RM} ${LIB}

re : fclean all

.PHONY:	all libftprintf clean fclean re