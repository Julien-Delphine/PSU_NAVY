/*
** EPITECH PROJECT, 2020
** navy
** File description:
** handling errors
*/

#include "navy.h"

int errors_numbers(char *buffer)
{
    int j = 3;
    int k = 6;

    for (int i = 0; i != 3; i++) {
        if (buffer[j] < '1' || buffer[j] > '8')
            return (84);
        j += 8;
    }
    for (int i = 0; i != 4; i++) {
        if (buffer[k] < '1' || buffer[j] > '8')
            return (84);
        k += 8;
    }
    return (0);
}

int errors_letters(char *buffer)
{
    int j = 2;
    int k = 5;

    for (int i = 0; i != 3; i++) {
        if (buffer[j] < 'A' || buffer[j] > 'H')
            return (84);
        j += 8;
    }
    for (int i = 0; i != 4; i++) {
        if (buffer[k] < 'A' || buffer[j] > 'H')
            return (84);
        k += 8;
    }
    return (0);
}

int errors_splitter(char *buffer)
{
    int j = 1;
    int k = 4;

    for (int i = 0; i != 4; i++) {
        if (buffer[j] != ':')
            return (84);
        j += 8;
    }
    for (int i = 0; i != 4; i++) {
        if (buffer[k] != ':')
            return (84);
        k += 8;
    }
    return (0);
}

int handle_errors(char *buffer)
{
    if (errors_splitter(buffer) == 84)
        return (84);
    if (errors_letters(buffer) == 84)
        return (84);
    if (errors_numbers(buffer) == 84)
        return (84);
    if (errors_pos(buffer) == 84)
        return (84);
    if (size_file(buffer) == 84)
        return (84);
    return (0);
}