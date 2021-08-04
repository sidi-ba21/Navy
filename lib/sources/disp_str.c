/*
** EPITECH PROJECT, 2021
** disp_string
** File description:
** .c
*/
#include <stdarg.h>
#include "../includes/bsprintf.h"

void disp_str(va_list list)
{
    my_putstr(va_arg(list, char *));
}
