/*
** EPITECH PROJECT, 2020
** navy
** File description:
** player main
*/

#include "navy.h"

char *find_coordonates(int x, int y)
{
    char *coordonates = malloc(sizeof(char) * 3);
    char *alpha = "ABCDEFGH";
    char *nb = "012345678";

    coordonates[1] = nb[x - 1];
    coordonates[0] = alpha[y / 2 - 1];
    coordonates[2] = '\0';
    return (coordonates);
}

void verif_attack(char **map, coord_t *coord, int pid_1)
{
    char *coordonates;

    if (map[coord->x][coord->y] != '.' && map[coord->x][coord->y] != 'o') {
        kill(pid_1, SIGUSR1);
        coordonates = find_coordonates(coord->x, coord->y);
        my_printf("%s: hit\n", coordonates);
        map[coord->x][coord->y] = 'x';
    }
    else {
        kill(pid_1, SIGUSR2);
        coordonates = find_coordonates(coord->x, coord->y);
        my_printf("%s: missed\n", coordonates);
        map[coord->x][coord->y] = 'o';
    }
}

void connection(int sig, siginfo_t *info, void *context)
{
    static int i = 0;
    (void) sig;
    (void) info;
    (void) context;

    if (i == 0) {
        my_printf("successfully connected\n");
        i++;
    }
}

int game(int pid_2, char **av, map_t *map)
{
    int fd = open(av[1], O_RDONLY);
    map->fst_player_en = set_map(map->fst_player_en);
    int game_int;

    if (set_boat(av[1], map, 1, fd) == 84)
        return (84);
    while (1) {
        print_turn_fst(map);
        game_int = check_win_fst(map);
        if (game_int != 4)
            return (game_int);
        if (read_entry(map->fst_player_en, pid_2) == 84)
            return (84);
        game_int = check_win_fst(map);
        if (game_int != 4)
            return (game_int);
        get_en_shot(map->fst_player, pid_2);
    }
    return (0);
}

int start_game(int pid_1, map_t *map)
{
    struct sigaction sa;
    int game_int;

    sa.sa_sigaction = connection;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    pause();
    while (1) {
        print_turn_scd(map);
        game_int = check_win_scd(map);
        if (game_int != 4)
            return (game_int);
        get_en_shot(map->scd_player, pid_1);
        if ((game_int = check_win_scd(map)) != 4)
            return (game_int);
        if (read_entry(map->scd_player_en, pid_1) == 84)
            return (84);
    }
    return (0);
}