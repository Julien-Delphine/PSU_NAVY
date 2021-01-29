/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** Include for Navy
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../lib/my/include/lib.h"
#include <fcntl.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <string.h>

#ifndef NAVY_
#define NAVY_

typedef struct sigaction sigact_t;

typedef struct map
{
    char **fst_player;
    char **fst_player_en;
    char **scd_player;
    char **scd_player_en;
    int column;
    int line;
    int column_2;
    int line_2;
    char boat_length;
} map_t;

typedef struct coord
{
    int x;
    int y;
} coord_t;

int glb;
void print_usage(void);
char **set_map(char **map);
void print_map(char **map);
int handle_errors(char *buffer);
int errors_pos(char *buffer);
int start_game(int pid_1, map_t *map);
int scd_player(char **av);
int first_player(char **av);
int set_boat(char *av, map_t *map, int map_nb, int fd);
int game(int pid_2, char **av, map_t *map);
int read_entry(char **map, int pid_2);
void print_turn_fst(map_t *map);
void print_turn_scd(map_t *map);
char *handle_errors_entry(char *buffer);
size_t file_size(const char *file);
int which_int(char c);
void verif_attack(char **map, coord_t *coord, int pid_1);
void get_en_shot(char **map, int pid_1);
void wait(int sig);
int size_file(char *buffer);
void start_message(void);
int check_file(char *av);
int check_map_enemy_scd(map_t *map);
int check_map_enemy_fst(map_t *map);
int check_my_map_fst(map_t *map);
int check_my_map_scd(map_t *map);
int check_win_fst(map_t *map);
int check_win_scd(map_t *map);
int check_boatsize(char *buffer);

#endif /* NAVY_ */