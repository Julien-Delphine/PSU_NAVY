/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get the next line
*/

#include "lib.h"

char *str_duplicate(char *tmp, char *buff)
{
    int i = 0;

    for (; tmp[i] != '\0'; i++)
        buff[i] = tmp[i];
    buff[i] = '\0';

    return (buff);
}

char *my_realloc(int size, char *buff)
{
    char *tmp = buff;

    buff = malloc(sizeof(char) * size + 1);
    buff = str_duplicate(tmp, buff);
    free(tmp);

    return (buff);
}

char get_next_character(int fd)
{
    static char buffer[READ_SIZE];
    static int size_read;
    static char *ptr_character;
    char character;

    if (size_read == 0)
    {
        size_read = read(fd, buffer, READ_SIZE);
        ptr_character = (char *)&buffer;
        if (size_read == 0)
            return ('\0');
    }
    size_read--;
    character = *ptr_character;
    ptr_character++;
    return (character);
}

char *get_next_line(int fd)
{
    char character = get_next_character(fd);
    char *buff = malloc(sizeof(char) * (READ_SIZE + 1));
    int size_buff = 0;

    if (buff == NULL)
        return (NULL);
    while (character != '\0' && character != '\n') {
        buff[size_buff] = character;
        character = get_next_character(fd);
        if (size_buff % (READ_SIZE) == 0)
            buff = my_realloc(size_buff + READ_SIZE + 1, buff);
        size_buff++;
    }
    buff[size_buff] = '\0';
    if (buff[0] == '\0' && character == '\0')
        return (NULL);
    return (buff);
}