/*
** EPITECH PROJECT, 2021
** disp_long
** File description:
** .c
*/
#include "../includes/bsprintf.h"
#include <stdio.h>
#include <stdarg.h>

unsigned my_put_long(unsigned long nb)
{
    if (nb > 9)
        my_put_long(nb / 10);
    my_putchar((nb % 10) + '0');
    return (0);
}

void disp_long(va_list list)
{
    my_put_long(va_arg(list, unsigned long));
}
