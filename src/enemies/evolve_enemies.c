/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** evolve_enemies.c
*/

#include "enemies.h"
#include "my.h"
#include "json.h"
#include "my_csfml_utils.h"
#include "my_game_struct.h"

//calculate enemy direction for x and y (0 <= x y <= 1)
static sfVector2f enemy_movement(enemy_t *enemy, game_t *game)
{
    sfVector2f player_pos = game->game->player->pos;
    sfVector2f enemy_pos;
    sfVector2f differential;
    float max_range;

    player_pos.x += 85;
    player_pos.y += 50;
    enemy_pos = sfSprite_getPosition(enemy->object->sprite);
    differential.x = player_pos.x - enemy_pos.x;
    differential.y = player_pos.y - enemy_pos.y;
    max_range = MAX(ABS(differential.x), ABS(differential.y));
    differential.x = (differential.x / MAX(1, max_range)) * enemy->speed;
    differential.y = (differential.y / MAX(1, max_range)) * enemy->speed;
    return differential;
}

void displace_enemies(enemy_node_t *all, game_t *game)
{
    static int last_time_moved = 0;
    int time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->game->clock));

    if (time - last_time_moved <= 16)
        return;
    last_time_moved = time;
    if (last_time_moved - time > 16)
        last_time_moved = 0;
    while (all) {
        sfSprite_move(all->enemy.object->sprite, enemy_movement(&(all->enemy), game));
        all = all->next;
    }
}

void remove_enemy_pv(enemy_node_t *enemy, int nb)
{
    if (enemy == NULL)
        return;
    enemy->enemy.pv -= nb;
    if (enemy->enemy.pv <= 0)
        enemy->enemy.type = -2;
}
