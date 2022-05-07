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

void remove_enemy_pv(enemy_node_t *enemy, int nb, game_t *game)
{
    if (enemy == NULL)
        return;
    enemy->enemy.pv -= nb;
    if (enemy->enemy.pv <= 0 && enemy->enemy.type != -2) {
        enemy->enemy.type = -2;
        game->game->player->exp += 200;
    }
}

int damage_enemy_zone(game_t *game, sfVector2f pos, int rayon, int damage)
{
    enemy_node_t *actual = game->game->enemies;
    sfVector2f e_pos;
    int enemis_touched = 0;

    while (actual) {
        e_pos = sfSprite_getPosition(actual->enemy.object->sprite);
        if (dist_two_points(e_pos, pos) <= rayon) {
            remove_enemy_pv(actual, damage, game);
            enemis_touched++;
        }
        actual = actual->next;
    }
    return enemis_touched;
}

int damage_enemy_rect(game_t *game, sfFloatRect rect, int dmg)
{
    enemy_node_t *actual = game->game->enemies;
    sfFloatRect enemy_rect = {0, 0, 0, 0};
    int enemis_touched = 0;

    while (actual) {
        enemy_rect = sfSprite_getGlobalBounds(actual->enemy.object->sprite);
        if (sfFloatRect_intersects((const sfFloatRect *) &rect,
            (const sfFloatRect *) &enemy_rect, NULL)) {
            remove_enemy_pv(actual, dmg, game);
            enemis_touched++;
        }
        actual = actual->next;
    }
    return enemis_touched;
}
