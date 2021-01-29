/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** Main for navy
*/

#include "navy.h"

int check_win_scd(map_t *map)
{
    if (check_map_enemy_scd(map) == 2)
        return (1);
    if (check_my_map_scd(map) == 1)
        return (0);
    return (4);
}

int check_win_fst(map_t *map)
{
    if (check_map_enemy_fst(map) == 2)
        return (1);
    if (check_my_map_fst(map) == 1)
        return (0);
    return (4);
}

void wait(int sig)
{
    if (sig == SIGUSR1)
        glb = 0;
}

int main_navy(int ac, char **av)
{
    int game_int;

    if (ac == 3) {
        if (check_file(av[2]) == 84)
            return (84);
        game_int = scd_player(av);
        return (game_int);
    }
    if (ac == 2) {
        if (check_file(av[1]) == 84)
            return (84);
        game_int = first_player(av);
        return (game_int);
    }
    return (0);
}

int main(int ac, char **av)
{
    int game_int;

    if (ac != 2 && ac != 3)
        return (84);
    if (my_strcmp(av[1], "-h") == 0 && ac == 2) {
        print_usage();
        return (0);
    }
    else {
        game_int = main_navy(ac, av);
        if (game_int == 84)
            return (84);
        if (game_int == 1)
            return (1);
        if (game_int == 0)
            return (0);
    }
}