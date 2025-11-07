# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 12:08:19 by ttsubo            #+#    #+#              #
#    Updated: 2025/11/07 00:56:40 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= SedIsForLosers 
TEST	= Test$(NAME)
CPP 	= c++
CPP_FLG = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp ReplaceAll.cpp OpenIOFile.cpp
OBJS = $(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CPP) $(CPP_FLG) $(OBJS) -o $@

test:
	$(CPP) $(CPP_FLG) -DTEST_MODE $(SRCS) -o $(TEST)	
	@echo ""

%.o:%.cpp
	$(CPP) $(CPP_FLG) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all test clean fclean re