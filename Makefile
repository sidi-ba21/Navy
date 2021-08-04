##
## EPITECH PROJECT, 2021
## Make file
## File description:
## make
##

SRC     =       sources/main.c	\
		sources/navy.c	\
		sources/display.c	\
		sources/game_loop.c	\
		sources/maps.c	\
		sources/utilitary.c	\
		sources/display_maps.c	\
		sources/send_and_touch.c	\
		sources/receive.c	\
		sources/cycle.c

OBJ     =       $(SRC:.c=.o)

NAME    =       navy

CFLAGS  +=      -I ./include -Wall -Wextra

LIB     =       -L ./lib -lmy

INCLUDE =       -I ./include/include.h

CRITERION       =       ./tests/tests.c --coverage -lcriterion

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C lib
	gcc -o $(NAME) $(OBJ) $(LIB) $(INCLUDE) -g3

clean:
	rm -f $(OBJ)
	rm -f sources/*~

fclean: clean fclean_test fclean_lib
	rm -f $(NAME)

re:     fclean all

fclean_lib: fclean
	make -C ./lib fclean

clean_test:
	rm -f *.gcno
	rm -f *.gcda

fclean_test: clean_test
	rm -f unit_tests

test_run:
	gcc -o unit_tests $(CRITERION) $(SRC) $(LIB) $(INCLUDE) $(CFLAGS)

.PHONY: all clean fclean re fclean_lib test clean_test
