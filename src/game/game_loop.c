/*
** EPITECH PROJECT, 2022
** GAME_LOOP_C
** File description:
** game_loop
*/

#include "my_game_struct.h"
#include "my.h"
#include "keyboard.h"

static void poll_event_keys(game_t *game)
{
    game->keys = get_keyboard_input(game->keys, game->window->window);
    if (game->keys[sfKeyEscape])
        game->status->end_game = 1;
    if (game->keys[sfKeyP])
        game->status->end_game = 1;
    if (game->keys[sfKeyI])
        game->status->end_game = 1;
}

int game_loop(game_t *game)
{
    while (game->status->end_game == 0) {
        sfRenderWindow_clear(game->window->window, sfBlack);
        display_world(game);
        player_actions(game);
        poll_event_keys(game);
        sfRenderWindow_display(game->window->window);
    }
    game->status->end_game = 0;
    return 0;
}
