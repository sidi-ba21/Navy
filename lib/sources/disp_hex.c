/*
** EPITECH PROJECT, 2021
** disp_hexadecimal
** File description:
** .c
*/
#include <stdarg.h>
#include "../includes/bsprintf.h"

void my_put_hex(int nb)
{
    int variable;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 16) {
        variable = nb % 16;
        nb = nb / 16;
        my_put_hex(nb);
    }
    else if (nb > 0) {
        variable = nb % 16;
        nb = nb / 16;
    }
    if (variable > 9)
        my_putchar(variable + 87);
    else
        my_putchar(variable + 48);
}

void disp_hex(va_list list)
{
    my_put_hex(va_arg(list, int));
}
