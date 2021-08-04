/*
** EPITECH PROJECT, 2021
** display
** File description:
** .c
*/

#include "navy.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int my_getnbr(char const *str)
{
    int nb = 0;
    int n = 1;
    int i = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            n *= -1;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (nb * n);
        nb = (nb * 10 + (str[i] - 48));
        i++;
        if ((nb < 0 && nb != -2147483648 && n == -1) || (nb < 0 && n != -1))
            return (0);
    }
    return (nb * n);
}

void start_game(int ac, char **av)
{
    if (ac == 2) {
        my_printf("my_pid: %d\n", getpid());
        my_printf("waiting for enemy connection...\n\n");
    }

    if (ac == 3) {
        my_printf("my_pid: %d\n", getpid());
        pid_t pide = my_getnbr(av[1]);
        singleton(1, pide);
        kill(pide, SIGUSR1);
    }
}
