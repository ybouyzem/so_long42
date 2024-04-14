# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 02:20:58 by ybouyzem          #+#    #+#              #
#    Updated: 2024/04/14 06:07:39 by ybouyzem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAN_C = so_long.c parssing.c so_long_utils1.c so_long_utils2.c  ft_split.c\

MAN_OBJS = $(MAN_C:.c=.o)

NAME = so_long

$(NAME) : $(MAN_OBJS)
	cc -Wall -Wextra -Werror  $(MAN_OBJS) -o so_long
%.o : %.c so_long.h
	cc -Wall -Wextra -Werror  -c $< -o $@
	
all : $(NAME)

clean :
	rm -f $(MAN_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean