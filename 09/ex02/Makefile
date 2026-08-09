# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 13:01:35 by ttsubo            #+#    #+#              #
#    Updated: 2026/08/09 11:01:52 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = PmergeMe
CXX     = c++
CXX_FLG = -std=c++98 -Wall -Wextra -Werror -pedantic-errors

SRC		= main.cpp PmergeMe.cpp
OBJS	= $(SRC:%.cpp=%.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXX_FLG) $(OBJS) -o $@

%.o:%.cpp
	$(CXX) $(CXX_FLG) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: CXX_FLG += -DDEBUG
debug: re

.PHONY: all clean fclean re debug