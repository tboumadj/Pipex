# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 11:42:31 by tboumadj          #+#    #+#              #
#    Updated: 2022/09/29 17:36:05 by tboumadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

SRCS 		= ft_substr.c \
			ft_strnstr.c \
			ft_strjoin.c \
			ft_split.c \
			ft_strdup.c \
			ft_strlen.c


OBJS	= $(SRCS:%.c=%.o)

HEADER	= libft.h

##FLAGS	= -Wall -Werror -Wextra

.SILENT : $(OBJS)

$(NAME):
		gcc -c $(SRCS) -I ./includes
		ar rc $(NAME) $(OBJS)
.SILENT : $(OBJS) $(NAME)
all: $(NAME)

clean:
		/bin/rm -f $(OBJS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all