##
## EPITECH PROJECT, 2023
## my_teams_tmp
## File description:
## Makefile
##

NAME	=	myteams_server

SRC		=	$(wildcard src/*.c) \
			$(wildcard src/command/*.c)

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
