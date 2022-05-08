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

    if (game->Z > 0)
        i++;
    if (game->S > 0)
        i++;
    if (game->Q > 0)
        i++;
    if (game->D > 0)
        i++;
    if (i != 1)
        return 1;
    return 0;
}

int player_is_collide(game_t *game, int dir, int value)
{
    int i = -1;
    int j = 0;
    int map = get_current_map(game);
    int ret = 0;

    game->game->player->pos.x += dir > 0 ? value : 0;
    game->game->player->pos.y += dir == 0 ? value : 0;
    while (game->game->maps[map]->maps[1][++i]) {
        j = -1;
        while (game->game->maps[map]->maps[1][i][++j])
            ret = ((int)((game->game->player->pos.x + 8) / 64) == j ||
                (int)((game->game->player->pos.x - 8) / 64) + 1 == j) &&
                game->game->maps[map]->maps[1][i][j] != '0' &&
                ((int)((game->game->player->pos.y + 32) / 64) == i ||
                (int)((game->game->player->pos.y - 1) / 64) + 1 == i)
                ? 1 : ret;
    }
    return ret;
}

static char *get_new_map(game_t *game, int i, int dir)
{
    if (dir == LEFT_D)
        return game->game->maps[i]->left;
    if (dir == UP_D)
        return game->game->maps[i]->top;
    if (dir == RIGHT_D)
        return game->game->maps[i]->right;
    return game->game->maps[i]->bot;
}

static void handle_switch_map(game_t *game)
{
    int i = get_current_map(game);

    if (game->game->player->pos.x <= 0) {
        game->game->current = get_new_map(game, i, LEFT_D);
        game->game->player->pos.x =
            (game->game->maps[get_current_map(game)]->width - 1) * 64 - 1;
    }
    if (game->game->player->pos.y <= 0) {
        game->game->current = get_new_map(game, i, UP_D);
        game->game->player->pos.y =
            (game->game->maps[get_current_map(game)]->height - 1) * 64 - 1;
    }
    if (game->game->player->pos.x >= (game->game->maps[i]->width - 1) * 64) {
        game->game->current = get_new_map(game, i, RIGHT_D);
        game->game->player->pos.x = 1;
    }
    if (game->game->player->pos.y >= (game->game->maps[i]->height - 1) * 64) {
        game->game->current = get_new_map(game, i, DOWN_D);
        game->game->player->pos.y = 1;
    }
}

void player_move(game_t *game)
{
    int spd = 1;
    int count = game->game->player->move_spd;

    if (game->LSHIFT > 0 && game->game->in_dialogue == false &&
        game->game->player->stamina >= 1) {
            count *= 1.5;
            game->game->player->stamina -= 1;
    }
    more_than_one_key(game) ? (count /= 1.2) : (count = count);
    while (count--) {
        if (game->Z > 0 && player_is_collide(game, 0, -spd) != 0)
            game->game->player->pos.y += spd;
        if (game->S > 0 && player_is_collide(game, 0, spd) != 0)
            game->game->player->pos.y -= spd;
        if (game->Q > 0 && player_is_collide(game, 1, -spd) != 0)
            game->game->player->pos.x += spd;
        if (game->D > 0 && player_is_collide(game, 1, spd) != 0)
            game->game->player->pos.x -= spd;
    }
    handle_switch_map(game);
}
