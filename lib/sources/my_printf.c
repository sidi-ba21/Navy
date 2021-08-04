/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** printf
*/
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include "../includes/bsprintf.h"

static sort_flag_t sort[13] =
{
    {'c', &disp_char},
    {'s', &disp_str},
    {'d', &disp_nbr},
    {'i', &disp_nbr},
    {'u', &disp_un_nbr},
    {'%', &disp_perc},
    {'o', &disp_octal},
    {'b', &disp_un_b},
    {'x', &disp_hex},
    {'X', &disp_hexadecimal},
    {'S', &disp_non_print},
    {'p', &disp_pointer},
    {'l', &disp_long}
};

void my_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            for (int j = 0; j != 13; j++) {
                if (format[i] == sort[j].c)
                    sort[j].function(list);
            }
        }
        else
            my_putchar(format[i]);
    }
    va_end(list);
}
