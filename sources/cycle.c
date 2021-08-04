/*
** EPITECH PROJECT, 2021
** cycle
** File description:
** .h
*/
#include <navy.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

int attack_phase(void)
{
    if (win_singleton(0) == 14) {
        my_printf("\nI won\n");
        return (0);
    } my_printf("attack: ");
    char *buffer;
    size_t bufsize = 2;
    buffer = malloc(bufsize * sizeof(char));
    getline(&buffer, &bufsize, stdin);
    int a = buffer[0] - 64;
    int b = buffer[1] - 48;
    if (my_str_isgud(buffer) == 0) {
        my_printf("wrong position\n");
        attack_phase();
    } else {
        send_attack(a);
        send_attack(b);
        bilan_attack(a, b);
    }
    return (0);
}

void bilan_attack(int a, int b)
{
    int val = receive_attack();
    char cé = a + 64;
    char el = b + 48;

    if (val == 1) {
        my_printf("%c%c: hit\n\n", cé, el);
        fill_enemy(val, a, b);
        win_singleton(1);
    }

    if (val == 0) {
        my_printf("%c%c: missed\n\n", cé, el);
        fill_enemy(val, a, b);
    }

    display_round(2);
    defense_phase();
}

int defense_phase(void)
{
    if (lose_singleton(0) == 14) {
        my_printf("\nEnemy won\n");
        return (1);
    }

    my_printf("waiting for enemy's attack...\n");

    int c = receive_attack();
    int l = receive_attack();
    int fac = touch_or_not(c, l);

    bilan_defense(fac, c, l);

    return (1);
}

void bilan_defense(int facteur, int c, int l)
{
    usleep(50000);
    char cé = c + 64;
    char el = l + 48;

    if (facteur == 1) {
        my_printf("%c%c: hit\n\n", cé, el);
        send_attack(1);
        lose_singleton(1);
    }

    if (facteur == 0) {
        my_printf("%c%c: missed\n\n", cé, el);
        send_attack(0);
    }

    display_round(1);
    attack_phase();
}
