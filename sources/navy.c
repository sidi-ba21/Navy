/*
** EPITECH PROJECT, 2021
** navy
** File description:
** .c
*/

#include "navy.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

int singleton(bool set, int new_pid)
{
    static int pid = 0;

    if (set) {
        pid = new_pid;
    }
    return (pid);
}

void display_map(void)
{
    my_printf("my positions:\n");
    for (int i = 0; i != 10; i++) {
        for (int j = 0; j != 17; j++) {
            my_printf("%c", map[i][j]);
        }
        my_printf("\n");
    }
}

void get_pid(int sig, siginfo_t *info, void *context)
{
    (void)context;
    if (sig == 10) {
        int signalPid = info->si_pid;
        singleton(1, signalPid);
        kill(signalPid, SIGUSR2);
    }
    if (sig == 12) {
        my_printf("successfully connected\n\n");
    }
}

int navy(int ac, char **av)
{
    struct sigaction sa = {0};
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &get_pid;
    start_game(ac, av);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    pause();

    if (singleton(0, 0) != 0 && ac == 2)
        my_printf("enemy connected\n\n");

    if (game_loop(ac, av) == 1)
        return (1);
    else
        return (0);

    return (0);
}
