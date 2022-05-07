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
    if (game->TAB == 2 || game->I == 2)
        game = inventory(game);
}

void update_player_status(game_t *game)
{
/*     static int last_sec = 0;
 */
    if (game->game->player->exp > game->game->player->max_exp) {
        game->game->player->exp = 0;
        game->game->player->max_exp += game->game->player->max_exp / 3;
        game->comp->comp_points += 1;
    }
/*     if (sfTime_asSeconds(sfClock_getElapsedTime(game->game->clock)) - last_sec > 0.5) {
        if (game->game->player->stamina < game->game->player->max_stamina)
            game->game->player->stamina += 0.4;
        last_sec = sfTime_asSeconds(sfClock_getElapsedTime(game->game->clock));
    } */
}

void update_game_status(game_t *game)
{
    update_player_status(game);
    if (MUSICG("our_home.flac") == NULL || MUSICG("death_mountains.flac")
        == NULL || MUSICG("mysterious_chasm.flac") == NULL)
        return;
    if (my_strcmp(game->game->current,"field") == 0 && sfMusic_getStatus(MUSICG("death_mountains.flac")) != 2) {
        sfMusic_play(MUSICG("death_mountains.flac"));
        if (sfMusic_getStatus(MUSICG("mysterious_chasm.flac")) == 2)
            sfMusic_stop(MUSICG("mysterious_chasm.flac"));
        if (sfMusic_getStatus(MUSICG("our_home.flac")) == 2)
            sfMusic_stop(MUSICG("our_home.flac"));
    }
    if (my_strcmp(game->game->current,"town") == 0 && sfMusic_getStatus(MUSICG("mysterious_chasm.flac")) != 2) {
        sfMusic_play(MUSICG("mysterious_chasm.flac"));
        if (sfMusic_getStatus(MUSICG("our_home.flac")) == 2)
            sfMusic_stop(MUSICG("our_home.flac"));
        if (sfMusic_getStatus(MUSICG("death_mountains.flac")) == 2)
            sfMusic_stop(MUSICG("death_mountains.flac"));
    }
    if ((my_strcmp(game->game->current,"house") == 0 || my_strcmp(game->game->current,"garden") == 0) && sfMusic_getStatus(MUSICG("our_home.flac")) != 2) {
        sfMusic_play(MUSICG("our_home.flac"));
        if (sfMusic_getStatus(MUSICG("mysterious_chasm.flac")) == 2)
            sfMusic_stop(MUSICG("mysterious_chasm.flac"));
        if (sfMusic_getStatus(MUSICG("death_mountains.flac")) == 2)
            sfMusic_stop(MUSICG("death_mountains.flac"));
    }
}

int game_loop(game_t *game)
{
    transition(game, 2);
    game->game->samples_enemies = create_enemies_array();
    if (game->game->samples_enemies == NULL)
        return 84;
    while (game->status->end_game == 0 && sfRenderWindow_isOpen
            (game->window->window)) {
        sfRenderWindow_clear(game->window->window, sfBlack);
        set_correct_window_size(game->window);
        main_enemies(game->game->enemies, game);
        display_world(game);
        update_game_status(game);
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
