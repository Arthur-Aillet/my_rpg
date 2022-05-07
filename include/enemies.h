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

#define PLAYER_OFFSET_X 85
#define PLAYER_OFFSET_Y 50

void displace_enemies(enemy_node_t *all, game_t *game);
enemy_node_t *spawn_ennemies(int nb, enemy_t *types, game_t *game);
enemy_t *create_enemies_array(void);
void display_enemies(game_t *game, enemy_node_t *enemies);
void free_enemies(enemy_node_t *enemies);
void remove_enemy_pv(enemy_node_t *enemy, int nb);
int damage_enemy_zone(game_t *game, sfVector2f pos, int rayon, int damage);
void move_from_type(enemy_node_t *enemy, game_t *game);
void change_status(enemy_node_t *enmy, game_t *game);
