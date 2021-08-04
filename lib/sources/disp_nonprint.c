/*
** EPITECH PROJECT, 2021
** disp non printable characters
** File description:
** .c
*/
#include <stdarg.h>
#include "../includes/bsprintf.h"

void my_put_octal(int nb);

void my_put_non_print(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putstr("\\");
            my_put_octal(str[i]);
            i++;
        }else {
            my_putchar(str[i]);
            i++;
        }
    }
}

void disp_non_print(va_list list)
{
    my_put_non_print(va_arg(list, char *));
}
