/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** display_enemies.c
*/

#include "enemies.h"
#include "my.h"
#include "my_csfml_utils.h"
#include "my_game_struct.h"

void display_enemies(game_t *game, enemy_node_t *all)
{
    while (all) {
        if (all->enemy.type >= 0)
            sfRenderWindow_drawSprite(game->window->window,
                all->enemy.object->sprite, NULL);
        all = all->next;
    }
}
