##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME	=	myteams_cli

SRC		=	./main.c \
			$(wildcard ../src/*.c)

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I ./include

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -g -o $(NAME) $(OBJ) $(CFLAGS) -g

clean:
		rm -rf $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all
