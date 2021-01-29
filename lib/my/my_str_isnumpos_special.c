/*
** EPITECH PROJECT, 2020
** matchsticks
** File description:
** str is num pos for str with \n
*/

int my_str_isnumpos_special(char const *str)
{
    int i = 0;

    while (str[i] != '\n') {
        if (str[i] < '0' || str[i] > '9')
            return (84);
        i++;
    }
    return (0);
}