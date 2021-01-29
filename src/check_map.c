/*
** EPITECH PROJECT, 2020
** check_map
** File description:
** check if there is any boat on the map
*/

#include "navy.h"

int check_my_map_scd(map_t *map)
{
    int count = 0;

    for (int i = 0; map->scd_player_en[i] != NULL; i++) {
        for (int j = 0; map->scd_player_en[i][j] != '\0'; j++) {
            if (map->scd_player_en[i][j] == 'x')
                count++;
        }
    }
    if (count == 14) {
        print_turn_scd(map);
        my_printf("\nI won\n");
        return (1);
    }
    return (0);
}

int check_my_map_fst(map_t *map)
{
    int count = 0;

    for (int i = 0; map->fst_player_en[i] != NULL; i++) {
        for (int j = 0; map->fst_player_en[i][j] != '\0'; j++) {
            if (map->fst_player_en[i][j] == 'x')
                count++;
        }
    }
    if (count == 14) {
        print_turn_fst(map);
        my_printf("\nI won\n");
        return (1);
    }
    return (0);
}

int check_line_enemy(char **map, int i)
{
    for (int j = 2; j <= 16; j++) {
        if (map[i][j] == '2' || map[i][j] == '3' || map[i][j] == '4'
        || map[i][j] == '5')
            return (1);
    }
    return (0);
}

int check_map_enemy_scd(map_t *map)
{
    for (int i = 2; i < 9; i++) {
        if (check_line_enemy(map->scd_player, i) == 1)
            return (1);
    }
    print_turn_scd(map);
    my_printf("\nEnemy won\n");
    return (2);
}

int check_map_enemy_fst(map_t *map)
{
    for (int i = 2; i < 9; i++) {
        if (check_line_enemy(map->fst_player, i) == 1)
            return (1);
    }
    print_turn_fst(map);
    my_printf("\nEnemy won\n");
    return (2);
}