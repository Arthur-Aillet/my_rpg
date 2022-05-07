/*
** EPITECH PROJECT, 2022
** rpg - player animation
** File description:
** here be moving animations
*/

#pragma once

#include "my_csfml_utils.h"
#include "my_game_struct.h"

#define PLAYER_ANIM player_animations[state].spritesheet->sprite

typedef struct animation_s {
    object_t *spritesheet;
    int step_size;
    int hsize;
    int animation_size;
} animation_t;

animation_t *place_player(sfRenderWindow *window, sfVector2f pos, int state,
    player_t *player);
