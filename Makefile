##
## EPITECH PROJECT, 2023
## my_teams_tmp
## File description:
## Makefile
##

all:
	@make -C server
	@make -C cli


clean:
	@make clean -C server
	@make clean -C cli

fclean: clean
	@make fclean -C server
	@make fclean -C cli

re: fclean all
