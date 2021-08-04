/*
** EPITECH PROJECT, 2021
** send_and_touch.c
** File description:
** send_and_touch.c
*/

#include "navy.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

char **map_singleton_enemy(int val, char **av)
{
    static char **map = NULL;

    if (val == 1)
        map = av;

    return (map);
}

char **map_singleton_mine(int val, char **av)
{
    static char **map = NULL;

    if (val == 1)
        map = av;

    return (map);
}

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int touch_or_not(int a, int b)
{
    char **maps = map_singleton_enemy(0, NULL);

    if (is_num(maps[b + 1][2 * a]) == 1) {
        maps[b + 1][2 * a] = 'x';
        return (1);
    }
    else {
        if (maps[b + 1][2 * a] != 'x') {
            maps[b + 1][2 * a] = 'o';
        }
    }
    map_singleton_enemy(1, maps);
    return (0);
}
