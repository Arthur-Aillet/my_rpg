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
    button_t *controls;
    button_t *display;
    button_t *volume;
    button_t *quit;
    int status;
    sfText *screen_type_title;
    button_t *screen_type_right;
    button_t *screen_type_left;
    object_t *screen_type_background;
    button_t *screen_type_apply;
    sfText *screen_type_text;
    int screen_type_state;
    list_t *resolution;
    list_t *frame;
    list_t *keyboard;
    sfText *vsync_title;
    check_t *vsync;
    sfText *general_title;
    sfText *sfx_title;
    sfText *music_title;
    slider_t *general;
    slider_t *sfx;
    slider_t *music;
} options_menu_t;

void init_display_2(options_menu_t *option, game_t *game);
void update_list_frame(list_t *list, game_t *game);
void change_window(options_menu_t *option);
void init_display(game_t *game, options_menu_t *option);
int option(game_t *game);
int menu(game_t *game, item_t *items, competences_t *comp);
void silder_general_manager(game_t *game, options_menu_t *option);
void silder_music_manager(game_t *game, options_menu_t *option);
void init_volume(game_t *game, options_menu_t *option);
void silder_sfx_manager(game_t *game, options_menu_t *option);
