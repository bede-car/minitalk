# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 19:57:26 by bede-car          #+#    #+#              #
#    Updated: 2023/03/06 08:25:51 by bede-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------> colors <----------------#
GREEN = \033[32m
YELLOW = \e[0;33m
BLUE = \033[34m
RESET = \033[0m
#-------------> minitalk <--------------#
NAME				=	minitalk
HEADER				=	./includes/minitalk.h
HEADER_BONUS		=	./includes/minitalk_bonus.h
#--------------> utils <----------------#
LIB					=	./libftprintf/libftprintf.a
CFLAG				=	-Wall -Wextra -Werror -I.
MAKEFLAGS			=	--no-print-directory
RM					=	rm -f
#------------> mandatory <----------------#
PATH_MANDATORY		=	./mandatory/
#---------------> bonus <----------------#
PATH_BONUS			=	./bonus/
#--------------> client <----------------#
NAME_CLIENT			=	client
SOURCE_CLIENT 		= 	client.c
OBJS_CLIENT			=	$(addprefix $(PATH_MANDATORY), $(SOURCE_CLIENT:.c=.o)) 
#--------------> server <----------------#
NAME_SERVER			=	server 
SOURCE_SERVER 		=	server.c
OBJS_SERVER			=	$(addprefix $(PATH_MANDATORY), $(SOURCE_SERVER:.c=.o)) 
#-------------> client bonus <------------#
NAME_CLIENT_BONUS	=	client_bonus
SOURCE_CLIENT_BONUS	= 	client_bonus.c
OBJS_CLIENT_BONUS	=	$(addprefix $(PATH_BONUS), $(SOURCE_CLIENT_BONUS:.c=.o)) 
#-----------> server bonus <--------------#
NAME_SERVER_BONUS	=	server_bonus
SOURCE_SERVER_BONUS	=	server_bonus.c
OBJS_SERVER_BONUS	=	$(addprefix $(PATH_BONUS), $(SOURCE_SERVER_BONUS:.c=.o)) 
 

%.o:%.c ${HEADER} ${HEADER_BONUS}
	cc ${CFLAG} -c $< -o $@ 

all: libftprintf $(NAME_CLIENT) $(NAME_SERVER)
	@${RM} ${NAME_CLIENT_BONUS}
	@${RM} ${NAME_SERVER_BONUS}
	@echo "$(BLUE)>>> Minitalk mandatory is already avalaible to run !\n $(RESET)"

bonus: libftprintf $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	@${RM} ${NAME_CLIENT}
	@${RM} ${NAME_SERVER}
	@echo "$(BLUE)>>> Minitalk bonus is already avalaible to run !\n $(RESET)"
		
libftprintf:
	@make -C ./libftprintf
	@echo "$(GREEN)libftprintf done\n $(RESET)"

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIB)
	@echo "$(YELLOW)creating a client >>>>$(RESET)"
	cc  ${CFLAG} ${OBJS_CLIENT} ${LIB} -o $(NAME_CLIENT)
	@echo "$(GREEN)>>> client was created !\n $(RESET)"

$(NAME_SERVER): $(OBJS_SERVER) $(LIB)
	@echo "$(YELLOW)creating a server >>>>$(RESET)"
	cc ${CFLAG} $(OBJS_SERVER) ${LIB} -o $(NAME_SERVER)
	@echo "$(GREEN)>>> server was created !\n $(RESET)"

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIB)
	@echo "$(YELLOW)creating a client_bonus >>>>$(RESET)"
	cc  ${CFLAG} ${OBJS_CLIENT_BONUS} ${LIB} -o $(NAME_CLIENT_BONUS)
	@echo "$(GREEN)>>> client_bonus was created !\n $(RESET)"

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIB)
	@echo "$(YELLOW)creating a server_bonus >>>>$(RESET)"
	cc ${CFLAG} $(OBJS_SERVER_BONUS) ${LIB} -o $(NAME_SERVER_BONUS)
	@echo "$(GREEN)>>> server_bonus was created !\n $(RESET)"
	
clean :
	${RM} ${OBJS_CLIENT} 
	${RM} ${OBJS_SERVER} 
	${RM} ${OBJS_CLIENT_BONUS} 
	${RM} ${OBJS_SERVER_BONUS} 
	$(MAKE) clean -C ./libftprintf
	 
fclean : clean
	${RM} ${NAME_CLIENT}
	${RM} ${NAME_SERVER}
	${RM} ${NAME_CLIENT_BONUS}
	${RM} ${NAME_SERVER_BONUS}
	${RM} ${LIB}

re : fclean all

.PHONY:	all libftprintf clean fclean re