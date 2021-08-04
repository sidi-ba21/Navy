/*
** EPITECH PROJECT, 2021
** disp_un_nbr
** File description:
** .c
*/
#include <stdarg.h>
#include "../includes/bsprintf.h"

void disp_un_nbr(va_list list)
{
    my_put_un_nbr(va_arg(list, unsigned int));
}
