/*
** EPITECH PROJECT, 2022
** GAME_LOOP_C
** File description:
** game_loop
*/

#include "my_rpg.h"
#include "keyboard.h"
#include "enemies.h"
#include "my_game_struct.h"
#include "my.h"
#include "keyboard.h"
#include "particles.h"
#include "main_menu.h"

static void poll_event_keys(game_t *game)
{
    game->keys = get_keyboard_input(game->keys, game->window->window);
    if (game->ESC == 2)
        game->status->end_game = pause_menu(game);
    if (game->P == 2)
        game->status->end_game = 1;
    if (game->I == 2)
        game->status->end_game = 1;
    if (game->TAB == 2)
        game = inventory(game);
}

int game_loop(game_t *game)
{
    transition(game, 2);
    game->game->samples_enemies = create_enemies_array();
    if (game->game->samples_enemies == NULL)
        return 84;
    //game->game->enemies = spawn_ennemies(5, game->game->samples_enemies, game);
    while (game->status->end_game == 0 && sfRenderWindow_isOpen(game->window->window)) {
        sfRenderWindow_clear(game->window->window, sfBlack);
        set_correct_window_size(game->window);
        display_world(game);
        main_enemies(game->game->enemies, game);
        player_actions(game);
        poll_event_keys(game);
        sfRenderWindow_display(game->window->window);
    }
    game->game->pos_cam.x = 960;
    game->game->pos_cam.y = 540;
    sfView_setCenter(game->game->cam, game->game->pos_cam);
    sfRenderWindow_setView(game->window->window, game->game->cam);
    game->status->end_game = 0;
    return 0;
}
