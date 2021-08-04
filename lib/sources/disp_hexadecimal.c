/*
** EPITECH PROJECT, 2021
** disp_hexadecimal
** File description:
** .c
*/
#include <stdarg.h>
#include "../includes/bsprintf.h"

void my_put_hexadecimal(int nb)
{
    int variable;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 16) {
        variable = nb % 16;
        nb = nb / 16;
        my_put_hexadecimal(nb);
    }
    else if (nb > 0) {
        variable = nb % 16;
        nb = nb / 16;
    }
    if (variable > 9)
        my_putchar(variable + 55);
    else
        my_putchar(variable + 48);
}

void disp_hexadecimal(va_list list)
{
    my_put_hexadecimal(va_arg(list, int));
}
