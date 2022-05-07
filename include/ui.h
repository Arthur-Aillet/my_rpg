/*
** EPITECH PROJECT, 2022
** rpg - ui
** File description:
** user interface
*/

#pragma once

#include "csfml_libs.h"
#include "my_csfml_utils.h"
#include "my_game_struct.h"

void display_stamina(sfRenderWindow *window, float, float, object_t **parts);
void display_exp(sfRenderWindow *window, float, float, object_t **parts);
void display_ui(sfRenderWindow *window, player_t *player, sfVector2f pos);
void display_health(sfRenderWindow *window, float, float max, object_t **parts);
void display_hotbar(sfRenderWindow *window, player_t *player, object_t **parts);
void display_hotbar_items(game_t *game);
