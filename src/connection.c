/*
** EPITECH PROJECT, 2020
** navy
** File description:
** Connection file
*/

#include "navy.h"

int glb = 0;

void get_pid(int sig, siginfo_t *info, void *context)
{
    (void) sig;
    (void) context;
    glb = info->si_pid;
    my_printf("\nenemy connected\n");
}

int first_player(char **av)
{
    struct sigaction sa;
    map_t map;
    int pid = 0;
    map.fst_player = NULL;
    map.fst_player = set_map(map.fst_player);
    int game_int;

    sa.sa_sigaction = get_pid;
    sa.sa_flags = SA_SIGINFO;
    start_message();
    sigaction(SIGUSR2, &sa, NULL);
    pause();
    pid = glb;
    glb = 0;
    if (kill(pid, SIGUSR1) == -1)
        return (84);
    game_int = game(pid, av, &map);
    return (game_int);
}

int scd_player(char **av)
{
    map_t map;
    int pid_1;
    map.scd_player = NULL;
    map.scd_player = set_map(map.scd_player);
    map.scd_player_en = set_map(map.scd_player_en);
    int fd = open(av[2], O_RDONLY);
    int game_int;

    if ((pid_1 = my_strtol(av[1])) == -1)
        return (84);
    my_printf("my_pid: %d\n", getpid());
    if (set_boat(av[2], &map, 2, fd) == 84)
        return (84);
    if (kill(pid_1, SIGUSR2) == -1)
        return (84);
    game_int = start_game(pid_1, &map);
    return (game_int);
}