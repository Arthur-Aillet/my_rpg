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

void change_status(enemy_node_t *enmy, game_t *game)
{
    sfVector2f enmy_pos = sfSprite_getPosition(enmy->enemy.object->sprite);
    sfVector2f playr_pos = VCF {game->game->player->pos.x + PLAYER_OFFSET_X,
        game->game->player->pos.y + PLAYER_OFFSET_Y};

    if (enmy->enemy.status == 0 && dist_two_points(enmy_pos, playr_pos) < 15) {
        game->game->player->hurt = 5;
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
