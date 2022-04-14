/*
** EPITECH PROJECT, 2022
** GAME_LOOP_C
** File description:
** game_loop
*/

#include "my_game_struct.h"

void my_display_world(game_t *game)
{
    int i = 0;
    while (game->game->maps[i] && my_strcmp(game->game->current, game->game->maps[i]->name) != 0)
        i++;
    printf("%d\n", i);
}

int game_loop(game_t *game)
{
    while (game->status->end_game == 0) {
        my_display_world(game);
        sfRenderWindow_clear(game->window->window, sfBlack);
        sfRenderWindow_display(game->window->window);
    }
    return;
}