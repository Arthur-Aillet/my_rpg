/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** potions
*/

#pragma once

#include "my_csfml_utils.h"

typedef struct hammer_s {
    object_t *hammer;
    object_t *anvil;
    object_t *background;
    object_t *box_bar;
    object_t *for_bar;
    object_t *circle_full;
    object_t *circle_empty;
    int has_spawn;
    float points;
} hammer_t;

typedef struct potion_s {
    int difficulty;
    int current_step;
    int numbers_steps;
} potion_t;

void destroy_hammer_struct(hammer_t *hammer);
hammer_t *setup_hammer_struct(void);
hammer_t *setup_elements(void);
void hammer_loop(window_t *window, char *keys, object_t *mouse, potion_t *potion);
