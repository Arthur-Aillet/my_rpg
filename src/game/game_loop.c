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

void player_move_cinematic(game_t *game, int horizontal, int veritcal)
{
    float spd = 0.4;
    int count = game->game->player->move_spd;

    while (count--)
        game->game->player->pos = VCF{game->game->player->pos.x + spd *
            horizontal, game->game->player->pos.y + spd * veritcal};
}


void cinematic(game_t *game)
{
    object_t *bandeau = create_object("assets/img/bandeau.png", VCF{0, 0}, VCF{60, 50});

    game->ENTER = 0;
    game->game->player->pos.x = 876;
    game->game->player->pos.y = 440;
    while (game->status->end_game == 0 && sfRenderWindow_isOpen
            (game->window->window) && game->ENTER != 2) {
        sfRenderWindow_clear(game->window->window, sfBlack);
        set_correct_window_size(game->window);
        main_enemies(game->game->enemies, game);
        update_game_status(game);
        if (game->game->player->pos.x <= 1292) {
            display_world_cinematic(game, 1, 0, bandeau);
            player_move_cinematic(game, 1, 0);
        } else {
            display_world_cinematic(game, 0, 0, bandeau);
            player_move_cinematic(game, 0, 0);
        }
        sfSprite_setPosition(bandeau->sprite, VCF{game->game->pos_cam.x - 1920 / 2, game->game->pos_cam.y - 1080 / 2});
        game->keys = get_keyboard_input(game->keys, game->window->window);
        sfRenderWindow_display(game->window->window);
    }
    destroy_object(bandeau);
    game->game->player->pos.x = 1292;
    game->game->player->pos.y = 440;
}

int game_loop(game_t *game)
{
    transition(game, 2);
    game->game->samples_enemies = create_enemies_array();
    if (game->game->samples_enemies == NULL)
        return 84;
    cinematic(game);
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
