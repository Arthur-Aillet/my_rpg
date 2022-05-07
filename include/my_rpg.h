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
#define PLACE_PLAYER(x) place_player(game->window->window,\
                 game->game->player->pos, x, game->game->player)
#define ISDASH (game->game->player->dash == 1)

#define LEFT_D 0
#define UP_D 1
#define RIGHT_D 2
#define DOWN_D 3

#define ARMOR_VALUE game->items[61].power + game->items[62].power +\
                game->items[63].power + game->items[64].power

#define DOWN_WALK 0
#define UP_WALK 1
#define RIGHT_WALK 2
#define LEFT_WALK 3
#define IDLE 4
#define STAB 8
#define ATTACK 12

int my_error_handling(int ac, char **av);
int my_help(void);

int get_current_map(game_t *game);

int player_is_collide(game_t *game, int dir, int value);

game_t *init_game_struct(void);
control_t *init_game_status(void);
in_game_t *init_in_game_struct(void);
player_t *init_game_player(maps_t *field);
void init_map_objects(maps_t **maps, json_obj_t *obj, int i);
char *init_keys(void);

void intro(game_t *game);
void transition(game_t *game, int speed);

game_t *inventory(game_t *game);
item_t create_yellow_flower(item_t item, int number);
item_t *create_items(void);

int my_rpg(void);
int game_loop(game_t *game);

void display_world(game_t *game);
void display_world_cinematic(game_t *game, int ho, int ve, object_t *bandeau);
void display_map(game_t *game, int map, int layer, int space);
void display_player(game_t *game);
void display_player_cinematic(game_t *game, int horizontal, int vertical);

void do_attack(game_t *game);
void player_actions(game_t *game);
void player_move(game_t *game);
void die(game_t *game);
