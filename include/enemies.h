/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** enemies.h
*/

#pragma once

#include "my_game_struct.h"
#include "csfml_libs.h"
#include "my.h"
#include "my_csfml_utils.h"

void displace_enemies(enemy_node_t *all, game_t *game);
enemy_node_t *spawn_ennemies(int nb, enemy_t *types, game_t *game);
enemy_t *create_enemies_array(void);
void display_enemies(game_t *game, enemy_node_t *enemies);
void free_enemies(enemy_node_t *enemies);
