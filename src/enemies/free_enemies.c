/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** free_enemies.c
*/

#include "my_csfml_utils.h"
#include "my_game_struct.h"
#include "enemies.h"

void free_enemies(enemy_node_t *enemies)
{
    if (enemies && enemies->next)
        free_enemies(enemies->next);
    else
        return;
    destroy_object(enemies->enemy.object);
    free(enemies);
}
