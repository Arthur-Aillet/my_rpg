/*
** EPITECH PROJECT, 2022
** MY_PROJECT_H
** File description:
** MY_PROJECT_H
*/

#pragma once

#include "inventory_structures.h"
#include "json.h"
#include "my_game_struct.h"

#define BIG(x, y) ((x < y) ? (y) : (x))
#define SMALL(x, y) ((x < y) ? (x) : (y))
#define BETWEEN(var, x, y) (SMALL(x, y) <= var && var <= BIG(x, y))
#define TIME(x, y) BETWEEN(fmod(sfTime_asSeconds(sfClock_getElapsedTime(x))\
                , y), 0, 0.03)

int my_error_handling(int ac, char **av);
int my_help(void);

game_t *init_game_struct(void);
control_t *init_game_status(void);
in_game_t *init_in_game_struct(void);
void init_map_objects(maps_t **maps, json_obj_t *obj, int i);
char *init_keys(void);

void intro(window_t *win);
void transition(game_t *game, int speed);

item_t *inventory(sfRenderWindow *window, item_t *items, competences_t *comp, char *keys);
item_t create_yellow_flower(item_t item, int number);
item_t *create_items(void);

int my_rpg(int ac, char **av);
int game_loop(game_t *game);

void display_world(game_t *game);
void display_map(game_t *game, maps_t *maps, int i);
void display_player(game_t *game, int i);

void player_actions(game_t *game);
void player_move(game_t *game);
