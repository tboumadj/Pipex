# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 11:42:31 by tboumadj          #+#    #+#              #
#    Updated: 2022/10/27 10:41:04 by tboumadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

SRCS 		= ft_substr.c \
			ft_strnstr.c \
			ft_strjoin.c \
			ft_split.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strchr.c \
			ft_putstr_fd.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_putendl_fd.c


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