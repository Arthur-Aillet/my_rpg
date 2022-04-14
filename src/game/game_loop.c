/*
** EPITECH PROJECT, 2022
** GAME_LOOP_C
** File description:
** game_loop
*/

#include "my_game_struct.h"
#include "my.h"

void my_display_player(game_t *game, int i)
{
    
}

void my_display_world(game_t *game)
{
    int i = 0;

    while (game->game->maps[i] && my_strcmp(game->game->maps[i]->name, game->game->current) != 0)
        i++;
    my_display_map(game, game->game->maps[i], i);
    my_display_player(game, i);
}

int game_loop(game_t *game)
{
    while (game->status->end_game == 0) {
        sfRenderWindow_clear(game->window->window, sfBlack);
        my_display_world(game);
        sfRenderWindow_display(game->window->window);
    }
    return 0;
}