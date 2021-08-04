/*
** EPITECH PROJECT, 2021
** disp unsigned num in binary
** File description:
** .c
*/
#include <stdarg.h>
#include "../includes/bsprintf.h"

void my_put_un_bin(unsigned int nb)
{
    int variable;

    if (nb > 2) {
        variable = (nb % 2);
        nb = (nb - variable) / 2;
        my_put_un_bin(nb);
        my_putchar(variable + 48);
    }
    else
        my_putchar(48 + nb % 2);
}

void disp_un_b(va_list list)
{
    my_put_un_bin(va_arg(list, unsigned int));
}
