/*
** EPITECH PROJECT, 2021
** navy.h
** File description:
** navy.h
*/

#include <stdio.h>

typedef enum {
    F, T
}bool;

typedef struct maps_s {
        char *s;
        char **buf;
}maps_t;

int my_strcmp(char const *s1, char const *s2);

int my_str_isnum(char const *str);

void my_printf(const char *format, ...);

int navy(int ac, char **av);

void start_game(int ac, char **av);

int my_getnbr(char const *str);

int game_loop(int ac, char **av);

char **boat_vertical(maps_t *mapi, char *str, int n);

char **init_map(char **buf);

char **boat_plane(maps_t *mapi, char *str, int n);

char **maps_players(char *const filepath);

int error(int ac, char **av);

int touch_or_not(int a, int b);

int singleton(bool set, int new_pid);

int my_str_isgud(char const *str);

int my_strlen(char const *str);

void display_map(void);

void set_maps(int ac, char **av);

int receive_attack(void);

void cycle(void);

int attack_phase(void);

void bilan_attack(int a, int b);

int defense_phase(void);

void bilan_defense(int facteur, int c, int l);

int send_attack(int a);

char **map_singleton_mine(int val, char **av);

char **map_singleton_enemy(int val, char **av);

void print_maps(char **maps);

void display_round(int val);

int win_singleton(int value);

void fill_enemy(int factor, int a, int b);

int lose_singleton(int value);

int display_map_singleton(int value);

static const char map[10][18] = {
    " |A B C D E F G H",
    "-+---------------",
    "1|. . . . . . . .",
    "2|. . . . . . . .",
    "3|. . . . . . . .",
    "4|. . . . . . . .",
    "5|. . . . . . . .",
    "6|. . . . . . . .",
    "7|. . . . . . . .",
    "8|. . . . . . . ."
};
