/*
** EPITECH PROJECT, 2020
** check_boatsize
** File description:
** check boats size
*/

#include "navy.h"

int same_column(int j, char *buffer)
{
    char abcd[] = "ABCDEFGH";
    int index;
    int counter = 0;

    for (int k = 0; abcd[k] != buffer[j]; k++)
        index = k + 1;

    if (buffer[j + 1] == buffer[j + 4]) {
        for (; abcd[index] != buffer[j + 3];
        index++, counter++);
        if (counter + 1 != buffer[j - 2] - 48)
            return (84);
    }
    return (0);
}

int same_letter(int j, char *buffer)
{
    int i = buffer[j + 1] - '0';

    if (buffer[j] == buffer[j + 3]) {
        if ((buffer[j + 4] - 48) - i + 1 != buffer[j - 2] - 48)
            return (84);
    }
    return (0);
}

int check_boatsize(char *buffer)
{
    int j = 2;

    for (int k = 0; k != 4; k++) {
        if (same_letter(j, buffer) == 84)
            return (84);
        if (same_column(j, buffer) == 84)
            return (84);
        j += 8;
    }
    return (0);
}