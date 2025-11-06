# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 12:08:19 by ttsubo            #+#    #+#              #
#    Updated: 2025/11/06 08:24:05 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= SedIsForLosers 
CPP 	= c++
CPP_FLG = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp replace_all.cpp open_iofile.cpp
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