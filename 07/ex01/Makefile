# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 12:46:57 by ttsubo            #+#    #+#              #
#    Updated: 2026/05/03 13:50:27 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = iter
CXX     = c++
CXX_FLG = -std=c++98 -Wall -Wextra -Werror

SRC		= main.cpp 
OBJS	= $(SRC:%.cpp=%.o)

all:$(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME):$(OBJS)
	$(CXX) $(CXX_FLG) $(OBJS) -o $@

%.o:%.cpp
	$(CXX) $(CXX_FLG) -c $< -o $@

debug:
	$(MAKE) CXX_FLG="$(CXX_FLG) -DDEBUG" re

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug