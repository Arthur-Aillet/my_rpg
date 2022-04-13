/*
** EPITECH PROJECT, 2022
** MY_GAME_STRUCT_H
** File description:
** my_game_struct
*/

#pragma once

<<<<<<< HEAD
#include <SFML/Graphics.h>
#include "my_window_struct.h"
#include "my_controle_struct.h"
=======
    #include "my_window_struct.h"
    #include "my_controle_struct.h"
    #include "my_text.h"
    #include "my_sound.h"
    #include "my_csfml_utils.h"
>>>>>>> main

typedef struct maps_s {
    char *name;
    sfTexture *tex_ts;
    sfSprite* sp_ts;
    char **tileset;
    char **map;
    int def;
    int height;
    int width;
    char *left;
    char *right;
    char *top;
    char *bot;
} maps_t;

typedef struct player_s {
    sfTexture *tex_p;
    sfSprite *sp_p;
    char *name;
    int move_spd;
} player_t;

typedef struct in_game_s {
    maps_t **maps;
    player_t *player;
} in_game_t;

typedef struct game_s {
    char *keys;
    control_t *status;
    window_t *window;
<<<<<<< HEAD
    in_game_t *game;
=======
    object_t *mouse;
    font_t **fonts;
    sound_t **sounds;
>>>>>>> main
} game_t;
