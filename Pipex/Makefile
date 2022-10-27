# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 17:26:41 by tboumadj          #+#    #+#              #
#    Updated: 2022/10/27 10:56:02 by tboumadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FLAG
NAME 	=   pipex
CC 		=   gcc
FLAGS 	=   -Wall -Wextra -Werror -g
RM 		=   rm -f
CHECK = -fsanitize=address

#PATH
HEADER =   includes/pipex.h \
		includes/pipex_bonus.h

SRCS =   srcs/main.c \
		srcs/close.c \
		srcs/utils.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = bonus/main_bonus.c \
			bonus/utils_bonus.c \
			bonus/utils_pipex.c \
			bonus/close_pipex.c \
			bonus/path_bonus.c
OBJS_S = $(SRCS_BONUS:.c=.o)

#COULEURS
_RED    =   $'\x1b[31m
_GREEN  =   $'\x1b[32m

##
.o : .c $(HEADER) Makefile
		@$(CC) $(FLAGS) -I -c $< -o $(<:c=o) $@
	
$(NAME): $(OBJS)
		@echo "$(_RED)Compilation libft.a en cours...$(_END)"
		$(MAKE) -C libft/
	 	$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME) $(CHECK)
		@echo "$(_RED)Compilation de Pipex en cours...$(_END)"
		@echo "$(_GREEN)$(_BOLD)Fin de la compilation!$(_END)"

bonus :  $(OBJS_S)
		@echo "$(_RED)Compilation libft.a en cours...$(_END)"
		$(MAKE) -C libft/
	 	$(CC) $(FLAGS) $(OBJS_S) libft/libft.a -o $(NAME) $(CHECK)
		@echo "$(_RED)Compilation de Bonus - Pipex en cours...$(_END)"
		@echo "$(_GREEN)$(_BOLD)Fin de la compilation!$(_END)"

.SILENT : $(OBJS) $(NAME)

all     :   $(NAME)

clean   :
			$(MAKE) clean -C libft/
			$(RM) $(OBJS)
			$(RM) $(OBJS_S)
fclean  :	clean
			$(MAKE) fclean -C libft/
			$(RM) $(NAME)
re      :   fclean all
.PHONY  :   all clean fclean re