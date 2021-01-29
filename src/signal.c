/*
** EPITECH PROJECT, 2020
** navy
** File description:
** file for signal count
*/

#include "navy.h"

void handle_sigint(int sig)
{
    if (sig == SIGUSR1)
        glb++;
}

void get_en_shot(char **map, int pid_1)
{
    coord_t coord;
    struct timespec time, time2;
    time.tv_sec = 1;
    time2.tv_nsec = 0;

    my_printf("\nwaiting for enemy's attack...\n");
    signal(SIGUSR1, handle_sigint);
    pause();
    while (nanosleep(&time, &time2) == -1);
    coord.x = glb;
    kill(pid_1, SIGUSR1);
    glb = 0;
    signal(SIGUSR1, handle_sigint);
    while (nanosleep(&time, &time2) == -1);
    coord.y = glb;
    glb = 0;
    verif_attack(map, &coord, pid_1);
}