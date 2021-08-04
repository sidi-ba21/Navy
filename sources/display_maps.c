/*
** EPITECH PROJECT, 2021
** display_maps
** File description:
** .c
*/

#include "navy.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void fill_enemy(int factor, int a, int b)
{
    char **maps = map_singleton_mine(0, NULL);

    if (factor == 1)
        maps[b + 1][2 * a] = 'x';

    if (factor == 0)
        maps[b + 1][2 * a] = 'o';

    map_singleton_mine(1, maps);
}

void print_maps(char **maps)
{
    for (int i = 0; i != 10; i++) {
        write(1,  maps[i], 17);
        my_printf("\n");
    }
    my_printf("\n");
}

void display_round(int val)
{
    if (getpid() < singleton(0, 0) && val == 1) {
        my_printf("my positions:\n");
        print_maps(map_singleton_enemy(0, NULL));
        my_printf("enemy's positions:\n");
        print_maps(map_singleton_mine(0, NULL));
    }
    if (getpid() > singleton(0, 0) && val == 2) {
        my_printf("my positions:\n");
        print_maps(map_singleton_enemy(0, NULL));
        my_printf("enemy's positions:\n");
        print_maps(map_singleton_mine(0, NULL));
    }
    if (val == 0) {
        my_printf("my positions:\n");
        print_maps(map_singleton_enemy(0, NULL));
        my_printf("enemy's positions:\n");
        print_maps(map_singleton_mine(0, NULL));
    }
}

char **empty_map(void)
{
    char **emap = malloc(sizeof(char *) * 10);

    for (int i = 0; i < 10; i++) {
        emap[i] = malloc(sizeof(char) * 18);
        for (int j = 0; j < 18; j++)
            emap[i][j] = map[i][j];
    }
    return (emap);
}

void set_maps(int ac, char **av)
{
    char **maps;
    char **emap = empty_map();

    if (ac == 2)
        maps = maps_players(av[1]);
    else if (ac == 3)
        maps = maps_players(av[2]);

    map_singleton_enemy(1, maps);
    map_singleton_mine(1, emap);
}
