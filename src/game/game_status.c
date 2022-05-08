/*
** EPITECH PROJECT, 2022
** game
** File description:
** game status
*/

#include "my_rpg.h"
#include "keyboard.h"
#include "enemies.h"
#include "my_game_struct.h"
#include "pnjs.h"
#include "my.h"
#include "inventory_prototypes.h"
#include "object_creation.h"
#include "keyboard.h"
#include "particles.h"
#include "main_menu.h"

static void update_player_status(game_t *game)
{
    if (game->game->player->exp > game->game->player->max_exp) {
        game->game->player->exp = 0;
        game->game->player->max_exp += game->game->player->max_exp / 3;
        game->comp->comp_points += 1;
    }
}

static void update_music(game_t *game)
{
    if (my_strcmp(game->game->current, "town") == 0 &&
        sfMusic_getStatus(MUSICG("mysterious_chasm.flac")) != 2) {
        sfMusic_play(MUSICG("mysterious_chasm.flac"));
        if (sfMusic_getStatus(MUSICG("our_home.flac")) == 2)
            sfMusic_stop(MUSICG("our_home.flac"));
        if (sfMusic_getStatus(MUSICG("death_mountains.flac")) == 2)
            sfMusic_stop(MUSICG("death_mountains.flac"));
    }
    if ((my_strcmp(game->game->current, "house") == 0 ||
        my_strcmp(game->game->current, "garden") == 0)
        && sfMusic_getStatus(MUSICG("our_home.flac")) != 2) {
        sfMusic_play(MUSICG("our_home.flac"));
        if (sfMusic_getStatus(MUSICG("mysterious_chasm.flac")) == 2)
            sfMusic_stop(MUSICG("mysterious_chasm.flac"));
        if (sfMusic_getStatus(MUSICG("death_mountains.flac")) == 2)
            sfMusic_stop(MUSICG("death_mountains.flac"));
    }
}

void update_game_status(game_t *game)
{
    update_player_status(game);
    if (MUSICG("our_home.flac") == NULL || MUSICG("death_mountains.flac")
        == NULL || MUSICG("mysterious_chasm.flac") == NULL)
        return;
    if (my_strcmp(game->game->current, "field") == 0 &&
        sfMusic_getStatus(MUSICG("death_mountains.flac")) != 2) {
        sfMusic_play(MUSICG("death_mountains.flac"));
        if (sfMusic_getStatus(MUSICG("mysterious_chasm.flac")) == 2)
            sfMusic_stop(MUSICG("mysterious_chasm.flac"));
        if (sfMusic_getStatus(MUSICG("our_home.flac")) == 2)
            sfMusic_stop(MUSICG("our_home.flac"));
    }
    update_music(game);
}
