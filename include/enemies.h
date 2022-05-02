/*
** EPITECH PROJECT, 2021
** my_rpg [WSL: Ubuntu]
** File description:
** enemies.h
*/

#pragma once

#include "csfml_libs.h"
#include "enemies.h"
#include "my.h"
#include "my_csfml_utils.h"
#include "my_game_struct.h"

typedef struct enemy_s {
    char *name;
    int type;
    int speed;
    int dps;
    int last_update;
    sfSprite *sprite;
    sfTexture *texture;
} enemy_t;

typedef struct enemy_node_s {
    enemy_t enemy;
    struct enemy_node_s *next;
} enemy_node_t;

void displace_enemies(enemy_node_t *all, game_t *game);
enemy_node_t *spawn_ennemies(int nb, enemy_t *types, game_t *game);
enemy_t *create_enemies_array(void);
void display_enemies(game_t *game, enemy_node_t *enemies);
