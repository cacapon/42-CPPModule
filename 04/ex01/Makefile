# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 12:35:13 by ttsubo            #+#    #+#              #
#    Updated: 2025/11/25 07:34:42 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Animals2
CPP 	= c++
CPP_FLG = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp 
OBJS = $(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CPP) $(CPP_FLG) $(OBJS) -o $@

%.o:%.cpp
	$(CPP) $(CPP_FLG) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all test clean fclean re