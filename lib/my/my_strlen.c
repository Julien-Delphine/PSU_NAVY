/*
** EPITECH PROJECT, 2020
** matchsticks
** File description:
** count nbr of char of a str
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}