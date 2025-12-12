# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 12:46:57 by ttsubo            #+#    #+#              #
#    Updated: 2025/12/11 07:19:21 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = array
CXX     = c++
CXX_FLG = -std=c++98 -Wall -Wextra -Werror

SRCS_DIR = src
INCS_DIR = inc
OBJS_DIR = obj

SRC		= main.cpp 
SRCS	= $(addprefix $(SRCS_DIR)/, $(SRC))
OBJS	= $(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)
all:$(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME):$(OBJS)
	$(CXX) $(CXX_FLG) $(OBJS) -o $@

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	$(CXX) $(CXX_FLG) -I $(INCS_DIR) -c $< -o $@

debug:
	$(MAKE) CXX_FLG="$(CXX_FLG) -DDEBUG" re

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug