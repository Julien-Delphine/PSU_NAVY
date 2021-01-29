/*
** EPITECH PROJECT, 2020
** matchsticks
** File description:
** my_atoi for \n
*/

int my_atoi(char const *str)
{
    int i;
    int n;

    i = 0;
    n = 0;
    if (str[0] == '-' && str[1] != '\n')
        i++;
    while (str[i] != '\n')
    {
        if ((str[i] < '0' || str[i] > '9'))
            return (0);
        n = n + str[i] - 48;
        n = n * 10;
        i++;
    }
    n /= 10;
    if (str[0] == '-')
        return (-1 * n);
    else
        return (n);
}