/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** all print function for navy
*/

#include "navy.h"

void start_message(void)
{
    my_printf("my_pid: %i\n", getpid());
    my_printf("waiting for enemy connection...\n");
}

void print_turn_scd(map_t *map)
{
    my_printf("\nmy positions:\n");
    print_map(map->scd_player);
    my_printf("\nenemy's positions:\n");
    print_map(map->scd_player_en);
}

void print_turn_fst(map_t *map)
{
    my_printf("\nmy positions:\n");
    print_map(map->fst_player);
    my_printf("\nenemy's positions:\n");
    print_map(map->fst_player_en);
}

void print_map(char **map)
{
    for (int i = 0; i != 10; i++)
        my_printf("%s\n", map[i]);
}

void print_usage(void)
{
    my_printf("USAGE\n");
    my_printf("      ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n");
    my_printf("      first_player_pid:  only for the 2nd player.  pid of");
    my_printf(" the first player\n");
    my_printf("      navy_positions:  file representing the positions");
    my_printf(" of the ships.\n");
}