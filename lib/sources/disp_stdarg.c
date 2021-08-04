/*
** EPITECH PROJECT, 2021
** Disp stdarg
** File description:
** disp
*/
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i++;
    }
}

void my_put_nbr(int nb)
{
    int variable;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb < 10) {
            my_putchar(nb + 48);
        }
        else {
            variable = (nb % 10);
            nb = (nb - variable) / 10;
            my_put_nbr(nb);
            my_putchar(variable + 48);
        }
    }
}

void my_put_un_nbr(unsigned int nb)
{
    int variable;

    if (nb < 10) {
        my_putchar(nb + 48);
    }
    else {
        variable = (nb % 10);
        nb = (nb - variable) / 10;
        my_put_nbr(nb);
        my_putchar(variable + 48);
    }
}
