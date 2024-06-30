# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 02:20:58 by ybouyzem          #+#    #+#              #
#    Updated: 2024/06/30 00:09:40 by ybouyzem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAN_C = so_long.c parssing.c so_long_utils1.c so_long_utils2.c ft_split.c floodfill.c images_utils.c map_utils.c\

MAN_OBJS = $(MAN_C:.c=.o)

LIBS = libs/libglfw3.a libs/libmlx42.a
NAME = so_long

$(NAME) : $(MAN_OBJS)
	cc -Wall -Wextra -Werror  -framework Cocoa -framework OpenGL -framework IOKit $(MAN_OBJS) -o so_long $(LIBS)

%.o : %.c so_long.h
	cc -Wall -Wextra -Werror -c $< -o $@
	
all : $(NAME)

clean :
	rm -f $(MAN_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean