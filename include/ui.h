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

void display_stamina(sfRenderWindow *window, float current, float max, object_t **parts);
void display_exp(sfRenderWindow *window, float current, float max, object_t **parts);
void display_ui(sfRenderWindow *window, player_t *player);
void display_health(sfRenderWindow *window, float current, float max, object_t **parts);
void display_ui(sfRenderWindow *window, player_t *palyer);
