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
#include "my_math.h"
#include "my_rpg.h"

//calculate enemy direction for x and y (0 <= x y <= 1)
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

void move_from_type(enemy_node_t *enemy, game_t *game)
{
    if (enemy->enemy.status == 0) {
        if (enemy->enemy.type == 0)
            sfSprite_move(enemy->enemy.object->sprite,
                enemy_forward(&(enemy->enemy), game));
    }
    if (enemy->enemy.status == 1) {
        if (enemy->enemy.type == 0) {
            sfSprite_move(enemy->enemy.object->sprite,
                enemy_backward(&(enemy->enemy), game));
            enemy->enemy.status_data -= 1;
        }
    }
}

void change_status(enemy_node_t *enmy, game_t *game)
{
    sfVector2f enmy_pos = sfSprite_getPosition(enmy->enemy.object->sprite);
    sfVector2f playr_pos = game->game->player->pos;

    playr_pos.x += PLAYER_OFFSET_X;
    playr_pos.y += PLAYER_OFFSET_Y;
    if (enmy->enemy.status == 0 && dist_two_points(enmy_pos, playr_pos) < 15) {
        enmy->enemy.status = 1;
        enmy->enemy.status_data = 100;
        enmy->enemy.speed += 1;
        game->game->player->health -= (enmy->enemy.dps - ARMOR_VALUE > 0) ?
            (enmy->enemy.dps - ARMOR_VALUE) : (0);
    }
    if (game->game->player->health <= 0) {
        transition(game, 5);
        die(game);
    }
    if (enmy->enemy.status == 1 && enmy->enemy.status_data <= 0) {
        enmy->enemy.status = 0;
        enmy->enemy.speed -= 1;
    }
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
        move_from_type(all, game);
        change_status(all, game);
        all = all->next;
    }
}
