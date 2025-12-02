# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/02 07:07:27 by ttsubo            #+#    #+#              #
#    Updated: 2025/12/02 07:12:51 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= Bureaucrat
CPP 	= c++
CPP_FLG = -std=c++98 -Wall -Wextra -Werror

SRCS = 	main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CPP) $(CPP_FLG) $(OBJS) -o $@

%.o:%.cpp
	$(CPP) $(CPP_FLG) -c $< -o $@

debug:
	$(MAKE) CPP_FLG="$(CPP_FLG) -DDEBUG" re

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all test clean fclean re debug