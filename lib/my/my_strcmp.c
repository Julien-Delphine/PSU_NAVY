/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** check if a str equals to an other
*/

int my_strcmp(char *str, char *str2)
{
    int i = 0;

    for (; str[i] == str2[i] && str[i] != '\0' && str2[i] != '\0'; i++);
    return (str[i] - str2[i]);
}