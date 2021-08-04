/*
** EPITECH PROJECT, 2021
** maps.c
** File description:
** maps.c
*/

#include "navy.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char **maps_players(char *const filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *str = malloc(sizeof(char) * 33);
    maps_t *mapi = malloc(sizeof(maps_t));

    if (mapi == NULL || fd == -1)
        return (NULL);
    mapi->s =  malloc(sizeof(char) * 4);
    mapi->buf = malloc(sizeof(char *) * 10);
    read(fd, str, 32);
    str[32] = '\0';
    mapi->buf = init_map(mapi->buf);
    for (int i = 0; i < 32; i += 8) {
        if (str[i + 2] == str[i + 5])
            mapi->buf = boat_vertical(mapi, &str[i], (i / 8));
        else if (str[i + 2] != str[i + 5] && str[i + 3] == str[i + 6])
            mapi->buf = boat_plane(mapi, &str[i], (i / 8));
    }
    return (mapi->buf);
}

char **init_map(char **buf)
{
    buf = malloc(sizeof(char *) * 10);
    for (int i = 0; i < 10; i++) {
        buf[i] = malloc(sizeof(char) * 18);
        for (int j = 0; j < 18; j++)
            buf[i][j] = map[i][j];
    }
    return (buf);
}

char **boat_vertical(maps_t *mapi, char *str, int n)
{
    int col = 1;
    int a = 0;
    int b = 0;

    mapi->s[0] = str[3];
    mapi->s[1] = str[6];
    mapi->s[2] = str[2];
    n = (n + 2) + 48;
    for (int i = 0; mapi->buf[0][i] != mapi->s[2]; i++)
        col = i;
    col++;
    for (int i = 0; mapi->buf[i][0] != mapi->s[0]; i++)
        a++;
    for (int i = 0; mapi->buf[i][0] != mapi->s[1]; i++)
        b++;
    for (int i = a; i <= b; i++)
        mapi->buf[i][col] = n;
    return (mapi->buf);
}

char **boat_plane(maps_t *mapi, char *str, int n)
{
    int a = 1;
    int b = 1;
    int l = 0;

    mapi->s[0] = str[3];
    mapi->s[1] = str[6];
    mapi->s[2] = str[2];
    mapi->s[3] = str[5];
    n = (n + 2) + 48;
    l = mapi->s[0] - '0' + 1;
    for (int i = 0; mapi->buf[0][i] != mapi->s[2]; i++)
        a = i;
    for (int j = 0; mapi->buf[0][j] != mapi->s[3]; j++)
        b = j;
    for (int i = a + 1; i < b + 3; i += 2 )
        mapi->buf[l][i] = n;
    return (mapi->buf);
}
