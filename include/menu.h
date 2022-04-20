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

typedef struct main_menu_s{
    object_t *back;
    object_t *title;
    button_t *new_game;
    button_t *continue_game;
    button_t *options;
    button_t *quit;
} main_menu_t;

int menu(game_t *game, item_t *items, competences_t *comp);
