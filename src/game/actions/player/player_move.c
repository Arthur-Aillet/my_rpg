/*
** EPITECH PROJECT, 2022
** PLAYER_MOVE_C
** File description:
** player_move
*/

#include "my_rpg.h"
#include "keyboard.h"

static int more_than_one_key(game_t *game)
{
    int i = 0;

    if (game->keys[sfKeyUp] || game->keys[sfKeyZ])
        i++;
    if (game->keys[sfKeyDown] || game->keys[sfKeyS])
        i++;
    if (game->keys[sfKeyLeft] || game->keys[sfKeyQ])
        i++;
    if (game->keys[sfKeyRight] || game->keys[sfKeyD])
        i++;
    if (i != 1)
        return 1;
    return 0;
}

int player_is_collide(game_t *game, int dir, int value)
{
    int i = -1;
    int j = 0;
    int map = 0;
    int ret = 0;

    game->game->player->pos.x += dir == 1 ? value : 0;
    game->game->player->pos.y += dir == 0 ? value : 0;
    while (game->game->maps[map] && my_strcmp(game->game->maps[map]->name,
        game->game->current) != 0)
        map++;
    while (game->game->maps[map]->map[++i]) {
        j = -1;
        while (game->game->maps[map]->map[i][++j])
            ret = ((int)((game->game->player->pos.x + 1)/ 64) == j ||
                (int)((game->game->player->pos.x - 1) / 64) + 1 == j) &&
                game->game->maps[map]->map[i][j] == '1' &&
                ((int)((game->game->player->pos.y + 1) / 64) == i ||
                (int)((game->game->player->pos.y - 1) / 64) + 1 == i) ? 1 : ret;
    }
    return ret;
}

void player_move(game_t *game)
{
    int spd = 1;
    int count = game->game->player->move_spd;

    game->keys = get_keyboard_input(game->keys, game->window->window);
    if (game->keys[sfKeyLShift])
            count *= 1.5;
        if (more_than_one_key(game))
            count /= 1.2;
    while (count--) {
        if (game->keys[sfKeyZ] && player_is_collide(game, 0, -spd) != 0)
            game->game->player->pos.y += spd;
        if (game->keys[sfKeyS] && player_is_collide(game, 0, spd) != 0)
            game->game->player->pos.y -= spd;
        if (game->keys[sfKeyQ] && player_is_collide(game, 1, -spd) != 0)
            game->game->player->pos.x += spd;
        if (game->keys[sfKeyD] && player_is_collide(game, 1, spd) != 0)
            game->game->player->pos.x -= spd;
    }
}
