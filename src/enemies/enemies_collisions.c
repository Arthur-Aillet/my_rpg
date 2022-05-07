/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** enemy_collisions.c
*/

#include "enemies.h"
#include "my.h"
#include "my_rpg.h"
#include "my_csfml_utils.h"
#include "my_game_struct.h"

static sfVector2f enemy_forward(enemy_t *enemy, game_t *game)
{
    sfVector2f player_pos = game->game->player->pos;
    sfVector2f enemy_pos;
    sfVector2f differential;
    float max_range;

    player_pos.x += PLAYER_OFFSET_X;
    player_pos.y += PLAYER_OFFSET_Y;
    enemy_pos = sfSprite_getPosition(enemy->object->sprite);
    differential.x = player_pos.x - enemy_pos.x;
    differential.y = player_pos.y - enemy_pos.y;
    max_range = MAX(ABS(differential.x), ABS(differential.y));
    differential.x = (differential.x / MAX(1, max_range)) * enemy->speed;
    differential.y = (differential.y / MAX(1, max_range)) * enemy->speed;
    enemy->direction = determinate_enemy_direction(differential);
    return differential;
}

static sfVector2f enemy_backward(enemy_t *enemy, game_t *game)
{
    sfVector2f player_pos = game->game->player->pos;
    sfVector2f enemy_pos;
    sfVector2f differential;
    float max_range;

    player_pos.x += PLAYER_OFFSET_X;
    player_pos.y += PLAYER_OFFSET_Y;
    enemy_pos = sfSprite_getPosition(enemy->object->sprite);
    differential.x = player_pos.x - enemy_pos.x;
    differential.y = player_pos.y - enemy_pos.y;
    max_range = MAX(ABS(differential.x), ABS(differential.y));
    differential.x = 0 - (differential.x / MAX(1, max_range)) * enemy->speed;
    differential.y = 0 - (differential.y / MAX(1, max_range)) * enemy->speed;
    enemy->direction = determinate_enemy_direction(differential);
    return differential;
}

static void move_from_type_backward(enemy_node_t *enemy, game_t *game)
{
    sfVector2f differential;
    sfVector2f enemy_pos = sfSprite_getPosition(enemy->enemy.object->sprite);

    if (enemy->enemy.status == 1) {
        if (enemy->enemy.type == 0) {
            differential = enemy_backward(&(enemy->enemy), game);
            if (enemy_is_collide(game, 0, differential, enemy_pos))
                differential = keep_only_xy(differential, 1);
            if (enemy_is_collide(game, 1, differential, enemy_pos))
                differential = keep_only_xy(differential, 0);
            sfSprite_move(enemy->enemy.object->sprite, differential);
            enemy->enemy.status_data -= 1;
        }
    }
}

void move_from_type(enemy_node_t *enemy, game_t *game)
{
    sfVector2f differential;
    sfVector2f enemy_pos = sfSprite_getPosition(enemy->enemy.object->sprite);

    if (enemy->enemy.status == 0) {
        if (enemy->enemy.type == 0) {
            differential = enemy_forward(&(enemy->enemy), game);
            if (enemy_is_collide(game, 0, differential, enemy_pos))
                differential = keep_only_xy(differential, 1);
            if (enemy_is_collide(game, 1, differential, enemy_pos))
                differential = keep_only_xy(differential, 0);
            sfSprite_move(enemy->enemy.object->sprite, differential);
        }
    }
    move_from_type_backward(enemy, game);
}

int enemy_is_collide(game_t *game, int xy, sfVector2f diff, sfVector2f enemypos)
{
    int i = -1;
    int j = 0;
    int map = get_current_map(game);
    int ret = 0;

    if (xy == 0)
        enemypos.x += diff.x;
    else
        enemypos.y += diff.y;
    while (game->game->maps[map]->maps[1][++i]) {
        j = -1;
        while (game->game->maps[map]->maps[1][i][++j])
            ret = ((int)((enemypos.x + 2) / 64) == j ||
                (int)((enemypos.x - 2) / 64) + 1 == j) &&
                game->game->maps[map]->maps[1][i][j] != '0' &&
                ((int)((enemypos.y + 32) / 64) == i ||
                (int)((enemypos.y - 2) / 64) + 1 == i)
                ? 1 : ret;
    }
    return ret;
}
