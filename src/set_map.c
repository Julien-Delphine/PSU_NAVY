/*
** EPITECH PROJECT, 2020
** set_map
** File description:
** set the map
*/

#include "navy.h"

char **all_line(int i, int j, char **map, char pos)
{
    for (; j != 2; j++) {
        if (j == 0)
            map[i][0] = pos;
        if (j == 1)
            map[i][1] = '|';
    }
    for (; j != 18; j++) {
        if (j % 2 == 0)
            map[i][j] = '.';
        if (j % 2 == 1)
            map[i][j] = ' ';
    }
    map[i][17] = '\0';
    return (map);
}

char **scd_line(int j, char **map)
{
    for (; j != 18; j++) {
        if (j == 1)
            map[1][1] = '+';
        else
            map[1][j] = '-';
    }
    map[1][17] = '\0';
    return (map);
}

char **first_line(int j, char **map)
{
    char pos = 'A';

    for (; j != 2; j++) {
        if (j == 0)
            map[0][0] = ' ';
        if (j == 1)
            map[0][1] = '|';
    }
    for (; j != 18; j++) {
        if (j % 2 == 0) {
            map[0][j] = pos;
            pos++;
        }
        if (j % 2 == 1)
            map[0][j] = ' ';
    }
    map[0][17] = '\0';
    return (map);
}

char **set_map(char **map)
{
    char pos = '1';
    int i = 0;
    int j = 0;

    map = malloc(sizeof(char *) * 11);
    for (; i != 2; i++) {
        map[i] = malloc(sizeof(char) * 18);
        j = 0;
        if (i == 0)
            map = first_line(j, map);
        if (i == 1)
            map = scd_line(j, map);
    }
    for (; i != 10; i++) {
        map[i] = malloc(sizeof(char) * 18);
        j = 0;
        map = all_line(i, j, map, pos);
        pos++;
    }
    map[i] = NULL;
    return (map);
}