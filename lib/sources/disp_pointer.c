/*
** EPITECH PROJECT, 2021
** disp pointer
** File description:
** .c
*/
#include <stdarg.h>
#include "../includes/bsprintf.h"
void my_put_hex(int nb);

void disp_pointer(va_list list)
{
    int p = va_arg(list, int);

    my_putstr("0x");
    my_put_hex(p);
}
