/*
** EPITECH PROJECT, 2022
** GAME_LOOP_C
** File description:
** game_loop
*/

#include "my_game_struct.h"

int my_game(game_t *game)
{
    sfRenderWindow_clear(game->window->window, sfBlack);
    sfRenderWindow_display(game->window->window);
    while (game->status->end_game == 0) {

    }
    return;
}