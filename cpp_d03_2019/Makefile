##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CPPFLAGS	=	-iquote include

SRC		=	ex00.c \
			ex01.c \
			ex02.c \
			ex03.c \
			ex04.c \
			ex05.c \
			ex06.c \
			ex07.c \
			ex08.c \
			ex07.c \
			ex08.c \
			ex09.c \
			ex10.c \
			ex11.c \
			ex12.c \
			ex13.c \
			ex14.c \
			ex15.c \
			ex16.c

OBJ		=	$(SRC:.c=.o)

NAME		=	str.out

CFLAGS		= -Wall -Wextra

all: $(NAME)

clean:
	rm -f $(OBJ)

$(NAME):	$(OBJ)
		ar rc libstring.a $(OBJ) 
	     
fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
