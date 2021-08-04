/*
** EPITECH PROJECT, 2021
** main
** File description:
** .c
*/

#include "navy.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void display_help(void)
{
    my_printf("USAGE\n");
    my_printf("    ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("    first_player_pid: only for the énd player. ");
    my_printf("pid of the first player.\n");
    my_printf("    navy_positions: file representing ");
    my_printf("the positions of the ships.\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        display_help();
    if (error(ac, av) == 84)
        return (84);
    if (navy(ac, av) == 1)
        return (1);
    else
        return (0);
    return (0);
}

int error(int ac, char **av)
{
    FILE *file = NULL;

    if (ac < 2 || ac > 3)
        return 84;
    if (ac == 3 && (my_str_isnum(av[1]) == 0))
        return 84;
    if (ac == 2)
        return 84;
    if (ac == 3)
        file = fopen(av[2], "r");
    if (ac == 2)
        file = fopen(av[1], "r");
    if (file == NULL)
        return 84;
    return 0;
}
