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

static void animate_enemy(enemy_node_t *enemy)
{
    enemy->enemy.rect.left = (enemy->enemy.rect.left +
        enemy->enemy.rect.width)
        % (enemy->enemy.rect.width * enemy->enemy.animation_steps);
    sfSprite_setTextureRect(enemy->enemy.object->sprite, enemy->enemy.rect);
}

void display_enemies(game_t *game, enemy_node_t *all)
{
    static int last_time_animated = 0;
    int time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->game->clock));

    if (last_time_animated > time)
        last_time_animated = 0;
    while (all) {
        if (time - last_time_animated > 120) {
            animate_enemy(all);
        }
        if (all->enemy.type >= 0) {
            sfRenderWindow_drawSprite(game->window->window,
                all->enemy.object->sprite, NULL);
        }
        all = all->next;
    }
    if (time - last_time_animated > 120)
        last_time_animated = time;
}
