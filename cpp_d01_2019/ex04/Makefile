##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CPPFLAGS	=	-iquote include

SRC		=	main.c \
			bitmap_header.c\
			drawing.c

OBJ		=	$(SRC:.c=.o)

NAME		=	bitmap

CFLAGS		= -Wall -Wextra

all: $(NAME)

clean:
	rm -f $(OBJ)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)
		@echo -e "\e[92;5m       ====BULDING DONE====      \e[0m"

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
