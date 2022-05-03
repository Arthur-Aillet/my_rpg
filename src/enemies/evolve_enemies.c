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
    sfVector2f enemy_pos = sfSprite_getPosition(enemy->object->sprite);
    sfVector2f differential =
        {player_pos.x - enemy_pos.x, player_pos.y - enemy_pos.y};
    float max_range = MAX(ABS(differential.x), ABS(differential.y));

    differential.x = (differential.x / MAX(1, max_range)) * enemy->speed;
    differential.y = (differential.y / MAX(1, max_range)) * enemy->speed;
    return differential;
}

void displace_enemies(enemy_node_t *all, game_t *game)
{
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
