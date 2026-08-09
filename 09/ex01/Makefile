# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 13:01:35 by ttsubo            #+#    #+#              #
#    Updated: 2026/08/09 08:59:23 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = RPN
CXX     = c++
CXX_FLG = -std=c++98 -Wall -Wextra -Werror -pedantic-errors

SRC		= main.cpp RPN.cpp
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

.PHONY: all clean fclean re