/*
** EPITECH PROJECT, 2022
** MY_GAME_STRUCT_H
** File description:
** my_game_struct
*/

#ifndef MY_GAME_STRUCT_H_
    #define MY_GAME_STRUCT_H_

#include <SFML/Graphics.h>
#include "my_window_struct.h"
#include "my_controle_struct.h"

typedef struct map_s {
    sfTexture *tex_ts;
    sfSprite* sp_ts;
    char **tileset;
    char **map;
    int height;
    int width;
} map_t;

typedef struct maps_s {
    char *map;
    map_t *field;
} maps_t;

typedef struct player_s {
    sfTexture *tex_p;
    sfSprite *sp_p;
    char *name;
    int move_spd;
} player_t;

typedef struct in_game_s {
    maps_t *maps;
    player_t *player;
} in_game_t;

typedef struct game_s {
    int *keys;
    control_t *status;
    window_t *window;
    in_game_t *game;
} game_t;

#endif /* !MY_GAME_STRUCT_H_ */
