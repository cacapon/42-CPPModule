# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 12:32:44 by ttsubo            #+#    #+#              #
#    Updated: 2025/11/18 00:38:26 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ClapTrap
CPP 	= c++
CPP_FLG = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp ClapTrap.cpp
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