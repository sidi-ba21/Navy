/*
** EPITECH PROJECT, 2021
** disp_binaire
** File description:
** binaire.c
*/
#include <stdarg.h>
#include "../includes/bsprintf.h"

void my_put_bin(int nb)
{
    int variable;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb > 2) {
            variable = (nb % 2);
            nb = (nb - variable) / 2;
            my_put_bin(nb);
            my_putchar(variable + 48);
        }
        else
            my_putchar(48 + nb % 2);
    }
}

void disp_bin(va_list list)
{
    my_put_bin(va_arg(list, int));
}
