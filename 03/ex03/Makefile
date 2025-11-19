# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 12:33:37 by ttsubo            #+#    #+#              #
#    Updated: 2025/11/19 06:30:51 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= DiamondTrap
CPP 	= c++
CPP_FLG = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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