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

void player_move(game_t *game)
{
    int spd = game->game->player->move_spd;

    if (game->keys[sfKeyLShift])
        spd *= 1.5;
    if (more_than_one_key(game))
        spd /= 1.2;
    game->keys = get_keyboard_input(game->keys, game->window->window);
    if (game->keys[sfKeyUp] || game->keys[sfKeyZ])
        game->game->player->pos.y -= spd;
    if (game->keys[sfKeyDown] || game->keys[sfKeyS])
        game->game->player->pos.y += spd;
    if (game->keys[sfKeyLeft] || game->keys[sfKeyQ])
        game->game->player->pos.x -= spd;
    if (game->keys[sfKeyRight] || game->keys[sfKeyD])
        game->game->player->pos.x += spd;
}
