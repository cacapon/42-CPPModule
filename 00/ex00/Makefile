NAME	= megaphone
CPP 	= c++
CPP_FLG = -std=c++98 -Wall -Wextra -Werror

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CPP) $(CPP_FLG) $< -o $@

%.o:%.cpp
	$(CPP) $(CPP_FLG) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re