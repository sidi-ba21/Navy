/*
** EPITECH PROJECT, 2021
** disp_nbr
** File description:
** .c
*/
#include <stdarg.h>
#include "../includes/bsprintf.h"

void disp_nbr(va_list list)
{
    my_put_nbr(va_arg(list, int));
}
