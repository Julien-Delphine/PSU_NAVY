/*
** EPITECH PROJECT, 2020
** navy
** File description:
** file for read entry by users
*/

#include "navy.h"

int send_signal(int nb_sig, int pid)
{
    for (int i = 0; i != nb_sig; i++) {
        if (kill(pid, SIGUSR1) == -1)
            return (84);
        usleep(1000);
    }
    return (0);
}

void attack(int sig)
{
    if (sig == SIGUSR1) {
        glb = 1;
        my_printf(" hit\n");
    }
    if (sig == SIGUSR2) {
        glb = 2;
        my_printf(" missed\n");
    }
}

int loop_signal(int x, int y, int pid, char *buffer)
{
    if (send_signal(x, pid) == 84)
        return (84);
    signal (SIGUSR1, wait);
    pause();
    glb = 0;
    if (send_signal(y, pid) == 84)
        return (84);
    my_printf("%s:", buffer);
    signal (SIGUSR1, attack);
    signal (SIGUSR2, attack);
    pause();
    return (0);
}

int use_entry(char *buffer, char **map, int pid)
{
    char *nb = malloc(sizeof(char) * 2);
    nb[0] = buffer[0] - 16;
    nb[1] = '\0';
    int x = my_strtol(buffer) + 1;
    int y = my_getnbr(nb) * 2;

    if (loop_signal(x, y, pid, buffer) == 84)
        return (84);
    if (glb == 1)
        map[x][y] = 'x';
    if (glb == 2)
        map[x][y] = 'o';
    glb = 0;
    return (0);
}

int read_entry(char **map, int pid)
{
    char *buffer = malloc(sizeof(char) * 3);
    int read_bytes;

    my_printf("\nattack: ");
    if ((read_bytes = read(0, buffer, 3)) == -1)
        return (84);
    buffer[my_strlen(buffer)] = '\0';
    if ((buffer = handle_errors_entry(buffer)) == NULL)
        return (84);
    buffer[2] = '\0';
    if (use_entry(buffer, map, pid) == 84)
        return (84);
    return (0);
}