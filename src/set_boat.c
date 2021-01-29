/*
** EPITECH PROJECT, 2020
** navy
** File description:
** function for adding boat to the map
*/

#include "navy.h"

void modif_first_map(map_t *map)
{
    map->fst_player[map->line][map->column] = map->boat_length;
    map->fst_player[map->line_2][map->column_2] = map->boat_length;
    if (map->column == map->column_2) {
        for (int i = map->line_2; i > map->line; i--) {
            map->fst_player[i][map->column] = map->boat_length;
        }
    }
    if (map->line == map->line_2) {
        for (int i = map->column_2; i > map->column; i--) {
            if (map->fst_player[map->line][i] == '.')
                map->fst_player[map->line][i] = map->boat_length;
        }
    }
}

void modif_scd_map(map_t *map)
{
    map->scd_player[map->line][map->column] = map->boat_length;
    map->scd_player[map->line_2][map->column_2] = map->boat_length;
    if (map->column == map->column_2) {
        for (int i = map->line_2; i > map->line; i--) {
            map->scd_player[i][map->column] = map->boat_length;
        }
    }
    if (map->line == map->line_2) {
        for (int i = map->column_2; i > map->column; i--) {
            if (map->scd_player[map->line][i] == '.')
                map->scd_player[map->line][i] = map->boat_length;
        }
    }
}

void boat_line(char *buffer, map_t *map, int map_nb)
{
    map->boat_length = buffer[0];
    map->column = which_int(buffer[2]) * 2;
    map->line = (buffer[3] - 48) + 1;
    map->column_2 = which_int(buffer[5]) * 2;
    map->line_2 = (buffer[6] - 48) + 1;

    if (map->column == 1)
        map->column = 2;
    if (map->line == 1)
        map->line = 2;
    if (map->column_2 == 1)
        map->column_2 = 2;
    if (map->line_2 == 1)
        map->line_2 = 2;
    if (map_nb == 1)
        modif_first_map(map);
    else if (map_nb == 2)
        modif_scd_map(map);
}

int set_boat(char *av, map_t *map, int map_nb, int fd)
{
    int read_bytes = 0;
    char *buffer = malloc(sizeof(char) * file_size(av) + 1);
    char *line = NULL;
    int j = 0;

    if (fd == -1)
        return (84);
    if ((read_bytes = read(fd, buffer, file_size(av))) == -1)
        return (84);
    for (int i = 0; buffer[i] != '\0'; i++, j = 0) {
        line = malloc(sizeof(char) * 9);
        for (; buffer[i] != '\n' && buffer[i] != '\0'; i++, j++)
            line[j] = buffer[i];
        line[j + 1] = '\0';
        boat_line(line, map, map_nb);
    }
    if (close(fd) == 84)
        return (84);
    return (0);
}