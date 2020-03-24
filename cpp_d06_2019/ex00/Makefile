##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CPPFLAGS	=	-iquote include

SRC		=	my_cat.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME		=	my_cat

CFLAGS		= -Wall -Wextra

CC = g++

all: $(NAME)

clean:
	rm -f *.o

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)
		@echo -e "\e[92;5m       ====BULDING DONE====      \e[0m"

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
