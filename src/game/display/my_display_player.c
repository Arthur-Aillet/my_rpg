/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_PLAYER_C
** File description:
** my_display_player
*/

#include "my_rpg.h"

void display_player(game_t *game, int i)
{
    game->keys = get_keyboard_input(game->keys, game->window->window);
    if (game->keys[sfKeyS]) {
        place_player(game->window->window, game->game->player->pos, 0);
    } else if (game->keys[sfKeyZ]) {
        place_player(game->window->window, game->game->player->pos, 1);
    } else if (game->keys[sfKeyD]) {
        place_player(game->window->window, game->game->player->pos, 2);
    } else if (game->keys[sfKeyA]) {
        place_player(game->window->window, game->game->player->pos, 3);
    } else {
        place_player(game->window->window, game->game->player->pos, 4);
    }
}
