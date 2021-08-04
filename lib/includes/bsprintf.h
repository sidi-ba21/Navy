/*
** EPITECH PROJECT, 2021
** bootstrap printf
** File description:
** bsprf
*/
#include <stdarg.h>
#ifndef MY_PROT__
#define MY_PROT__

typedef struct sort_flag
{
    char c;
    void (*function)(va_list);
}sort_flag_t;

int sum_numbers(int n, ...);

int  sum_strings_length(int n, ...);

void disp_stdarg(char *s, ...);

void my_printf(const char *format, ...);

void my_putchar(char c);

void my_putstr(char const *str);

void my_put_nbr(int nb);

void my_put_un_nbr(unsigned int nb);

void disp_char(va_list list);

void disp_str(va_list list);

void disp_nbr(va_list list);

void disp_un_nbr(va_list list);

void disp_perc(va_list list);

void disp_octal(va_list list);

void disp_bin(va_list list);

void disp_hex(va_list list);

void disp_hexadecimal(va_list list);

void disp_un_b(va_list list);

void disp_non_print(va_list list);

void disp_pointer(va_list list);

void disp_long(va_list list);
#endif
