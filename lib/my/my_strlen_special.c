/*
** EPITECH PROJECT, 2020
** matchsticks
** File description:
** count nbr of char of str finish by \n
*/

#include <stdio.h>

int my_strlen_special(char *str, int i)
{
    while (str[i] != '\n') {
        i++;
    }
    if (i != 7)
        return (84);
    return (0);
}