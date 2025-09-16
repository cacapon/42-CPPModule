# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 12:05:52 by ttsubo            #+#    #+#              #
#    Updated: 2025/09/16 10:49:51 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= my_dreams
CPP 	= c++
CPP_FLG = -std=c++98 -Wall -Wextra -Werror

SRCS = tests.cpp Account.cpp
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

.PHONY: all clean fclean re