##
## EPITECH PROJECT, 2020
## Navy
## File description:
## Makefile
##

SRC	=	src/main_navy.c		\
		src/print_function.c	\
		src/set_map.c		\
		src/handle_errors_pos.c	\
		src/handle_errors_boat.c	\
		src/connection.c	\
		src/game.c	\
		src/set_boat.c	\
		src/read_entry.c	\
		src/file_size.c	\
		src/signal.c	\
		src/which_int.c		\
		src/check_map.c		\
		src/check_boatsize.c

NAME	=	navy

CFLAGS	=	-Wall -Wextra -g

IFLAGS	=	-I./include/

LIB		=	-L lib/my/ -l my

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(CFLAGS) $(IFLAGS) $(SRC) $(LIB)

clean:
	make -C lib/my clean
	rm -f *.o
	rm -f *.~

fclean:
	make -C lib/my fclean
	rm -f $(NAME)
	rm -f *.~

re:	fclean all