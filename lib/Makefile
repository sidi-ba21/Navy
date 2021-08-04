##
## EPITECH PROJECT, 2021
## Make file
## File description:
## make
##

SRC     =	sources/disp_char.c	\
		sources/disp_perc.c	\
		sources/my_printf.c	\
		sources/disp_stdarg.c	\
		sources/disp_str.c	\
		sources/disp_nbr.c	\
		sources/disp_unbr.c	\
		sources/disp_octal.c	\
		sources/disp_binaire.c	\
		sources/disp_hex.c	\
		sources/disp_hexadecimal.c	\
		sources/disp_unbin.c	\
		sources/disp_nonprint.c	\
		sources/disp_pointer.c	\
		sources/disp_long.c	\
		sources/my_strcmp.c	\
		sources/my_str_isnum.c

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

CFLAGS  +=      -I ./includes -Wall -Wextra

LIB     =       -L -lmy

INCLUDE =       -I ./includes

all:    $(NAME)

$(NAME):        $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#*

fclean: clean
	rm -f $(NAME)

re:     fclean all

fclean_lib: fclean
	make -C ./lib/my/ fclean

.PHONY: all clean fclean re fclean_lib
