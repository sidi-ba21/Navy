/*
** EPITECH PROJECT, 2021
** r
** File description:
** .c
*/

#include "navy.h"
#include <signal.h>
#include <unistd.h>

int binary(int sig)
{
    static int val = 0;
    if (sig == 10)
        val = val << 1;
    if (sig == 12)
        val = ((val << 1) | 1);
    if (sig == 0)
        val = 0;
    return (val);
}

void catcher(int sig)
{
    binary(sig);
}

int receive_attack(void)
{
    struct sigaction sca = {0};
    sca.sa_handler = &catcher;

    for (int i = 4; i != 0; i--) {
        sigaction(SIGUSR1, &sca, NULL);
        sigaction(SIGUSR2, &sca, NULL);
        pause();
    }
    int ret = binary(1);
    binary(0);

    return (ret);
}
