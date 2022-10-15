# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboumadj@student.42mulhouse.fr <tboumadj>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 17:26:41 by tboumadj          #+#    #+#              #
#    Updated: 2022/10/14 19:40:46 by tboumadj@student ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =   Pipex
LIBFT =  libft/libft.a
SRCS =   srcs/main.c \
		srcs/close.c \
		srcs/utils.c

CC =   gcc
FLAGS =   -Wall -Wextra -Werror -g
RM =   rm -f
HEADER =   srcs/pipex.h
OBJS = $(SRCS:.c=.o)
CHECK = -fsanitize=address
# Couleurs
_RED    =   $'\x1b[31m
_GREEN  =   $'\x1b[32m

.c.o:
	$(CC) $(FLAGS) -I$(HEADER) -c $< -o $(<:c=o)
	
$(NAME): $(OBJS)
		@echo "$(_RED)Compilation libft.a en cours...$(_END)"
		$(MAKE) -C libft/
	 	$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME) $(CHECK)
		@echo "$(_RED)Compilation de Pipex en cours...$(_END)"
		@echo "$(_GREEN)$(_BOLD)Fin de la compilation!$(_END)"

.SILENT : $(OBJS) $(NAME)

all     :   $(NAME)

clean   :
			$(MAKE) clean -C libft/
			$(RM) $(OBJS)
fclean  :	clean
			$(MAKE) fclean -C libft/
			$(RM) $(NAME)
re      :   fclean all
.PHONY  :   all clean fclean re