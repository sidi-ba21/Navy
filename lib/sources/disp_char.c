/*
** EPITECH PROJECT, 2021
** disp_char
** File description:
** .c
*/
#include <stdarg.h>
#include "../includes/bsprintf.h"

void disp_char(va_list list)
{
    my_putchar(va_arg(list, int));
}
