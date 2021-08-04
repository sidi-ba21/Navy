/*
** EPITECH PROJECT, 2021
** disp_octal
** File description:
** .c
*/
#include <stdarg.h>
#include "../includes/bsprintf.h"

void my_put_octal(int nb)
{
    int variable;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb > 8) {
            variable = (nb % 8);
            nb = (nb - variable) / 8;
            my_put_octal(nb);
            my_putchar(variable + 48);
        }
        else
            my_putchar(48 + nb % 8);
    }
}

void disp_octal(va_list list)
{
    my_put_octal(va_arg(list, int));
}
