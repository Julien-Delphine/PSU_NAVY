/*
** EPITECH PROJECT, 2020
** navy
** File description:
** handling errors for boat positions
*/

#include "navy.h"

int check_file(char *av)
{
    int fd = open(av, O_RDONLY);
    int read_bytes = 0;
    char *buffer = malloc(sizeof(char) * file_size(av) + 1);

    if (fd == -1)
        return (84);
    if ((read_bytes = read(fd, buffer, file_size(av))) == -1)
        return (84);
    if (handle_errors(buffer) == 84)
        return (84);
    if (check_boatsize(buffer) == 84)
        return (84);
    if (close(fd) == -1)
        return (84);
    return (0);
}

int size_file(char *buffer)
{
    int i = 7;

    for (int k = 0; k != 3; k++, i += 8) {
        if (buffer[i] != '\n')
            return (84);
    }
    if (buffer[32] != '\0' && buffer[32] != '\n')
        return (84);
    return (0);
}

int errors_pos(char *buffer)
{
    int i = 2;
    int j = 3;
    int x = 5;
    int y = 6;

    for (int k = 0; k != 4; i += 8, j += 8, x += 8, y += 8, k++) {
        if (buffer[i] != buffer[x] && buffer[j] != buffer[y])
            return (84);
    }
    return (0);
}

char *handle_errors_entry(char *buffer)
{
    int read_bytes;

    while (buffer[0] > 72 || buffer[0] < 65) {
        my_printf("wrong position");
        my_printf("\nattack: ");
        if ((read_bytes = read(0, buffer, 3)) == -1)
            return (NULL);
    }
    while (buffer[1] > 56 || buffer[1] < 49) {
        my_printf("wrong position");
        my_printf("\nattack: ");
        if ((read_bytes = read(0, buffer, 3)) == -1)
            return (NULL);
    }
    return (buffer);
}