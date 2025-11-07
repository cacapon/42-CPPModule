# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 12:08:19 by ttsubo            #+#    #+#              #
#    Updated: 2025/11/07 01:03:15 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Harl
CPP 	= c++
CPP_FLG = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp Harl.cpp 
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