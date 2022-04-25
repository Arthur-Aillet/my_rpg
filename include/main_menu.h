/*
** EPITECH PROJECT, 2022
** my_rpg_main
** File description:
** menu
*/

#pragma once

#include "my_game_struct.h"
#include "my_button.h"
#include "inventory_structures.h"
#include "particles.h"

typedef struct main_menu_s{
    object_t *back;
    object_t *title;
    button_t *new_game;
    button_t *continue_game;
    button_t *options;
    button_t *quit;
    sfClock *clock;
    particle_t *particle;
} main_menu_t;

typedef struct options_menu_s{
    object_t *back;
    object_t *title;
    button_t *controls;
    button_t *display;
    button_t *volume;
    button_t *quit;
    button_t *vsync_on;
    button_t *vsync_off;
    bool vsync_status;
    object_t *general_back;
    object_t *general_front;
    object_t *general_slider;
    object_t *sfx_back;
    object_t *sfx_front;
    object_t *sfx_slider;
    object_t *music_back;
    object_t *music_front;
    object_t *music_slider;
    button_t *list_up;
    button_t *list_down;
    bool list_value;
} options_menu_t;

int option(game_t *game, item_t *items, competences_t *comp);
int menu(game_t *game, item_t *items, competences_t *comp);
