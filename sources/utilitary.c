/*
** EPITECH PROJECT, 2021
** utilitary
** File description:
** .c
*/

int display_map_singleton(int value)
{
    static int val = 0;

    if (value == 1)
        val++;

    if (value == 2)
        val = 0;

    return (val);
}

int lose_singleton(int value)
{
    static int counter = 0;

    if (value == 1)
        counter++;

    return (counter);
}

int win_singleton(int value)
{
    static int counter = 0;

    if (value == 1)
        counter++;

    return (counter);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_str_isgud(char const *str)
{
    int i = 0;

    if (str[0] == '\n')
        return (0);

    while (str[i] != '\n') {
        if (str[i] >= '1' && str[i] <= '8') {
            i++;
        }
        else if (str[i] >= 'A' && str[i] <= 'H') {
            i++;
        }
        else
            return (0);
    }
    return (1);
}
