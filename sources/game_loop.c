/*
** EPITECH PROJECT, 2021
** game_loop
** File description:
** .c
*/

#include "navy.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

int send_attack(int a)
{
    for (int i = 3; i >= 0; i--) {
        if (((a >> i) & 1) == 0)
            kill(singleton(0, 0), SIGUSR1);
        if (((a >> i) & 1) == 1)
            kill(singleton(0, 0), SIGUSR2);
        usleep(50000);
    }
    return (0);
}

int game_loop(int ac, char **av)
{
    set_maps(ac, av);

    if (getpid() < singleton(0, 0)) {
        display_round(0);
        if (attack_phase() == 0)
            return (0);
    }else {
        display_round(0);
        if (defense_phase() == 1)
            return (1);
    }

    return (0);
}
