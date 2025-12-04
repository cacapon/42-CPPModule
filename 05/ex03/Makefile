# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 12:39:36 by ttsubo            #+#    #+#              #
#    Updated: 2025/12/04 07:45:13 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= intern 
CPP 	= c++
CPP_FLG = -std=c++98 -Wall -Wextra -Werror

SRCS = 	main.cpp Bureaucrat.cpp AForm.cpp \
		PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp \
		Intern.cpp
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

.PHONY: all clean fclean re debug