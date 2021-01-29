/*
** EPITECH PROJECT, 2019
** my_strtol
** File description:
** my_strtol
*/

int my_strtol(char *str)
{
    int stock = 0;
    int i = 0;
    int counter = 0;

    while ((str[i] < '0' || str[i] > '9') && (str[i] != '\0'))
        i++;
    if ((str[0] < '0' || str[0] > '9') && str[i-1] == '-')
        counter++;
    while (str[i] >= '0' && str[i] <= '9') {
        stock = stock*10 + (str[i] - '0');
        i++;
    }
    if (counter == 1)
        stock = stock * (-1);
    return (stock);
}