/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** enemies_pv.c
*/

#include "enemies.h"
#include "my.h"
#include "json.h"
#include "my_csfml_utils.h"
#include "my_game_struct.h"
#include "my_math.h"

void remove_enemy_pv(enemy_node_t *enemy, int nb)
{
    if (enemy == NULL)
        return;
    enemy->enemy.pv -= nb;
    if (enemy->enemy.pv <= 0)
        enemy->enemy.type = -2;
}

int damage_enemy_zone(game_t *game, sfVector2f pos, int rayon, int damage)
{
    enemy_node_t *actual = game->game->enemies;
    sfVector2f e_pos;
    int enemis_touched = 0;

    while (actual) {
        e_pos = sfSprite_getPosition(actual->enemy.object->sprite);
        if (dist_two_points(e_pos, pos) <= rayon) {
            remove_enemy_pv(actual, damage);
            enemis_touched++;
        }
    }
    return enemis_touched;
}
