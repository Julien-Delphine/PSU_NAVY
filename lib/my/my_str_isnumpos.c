/*
** EPITECH PROJECT, 2020
** matchsticks
** File description:
** check if str is num positiv
*/

int my_str_isnumpos(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (84);
        i++;
    }
    return (0);
}