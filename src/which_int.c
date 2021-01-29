/*
** EPITECH PROJECT, 2020
** which_int
** File description:
** determinate which column
*/

#include "navy.h"

int which_int(char c)
{
    char check[] = "ABCDEFGH";

    for (int i = 0; i <= 8; i++) {
        if (c == check[i])
            return (i + 1);
    }
    return (0);
}