/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_WORLD_C
** File description:
** my_display_world
*/

#include "my_rpg.h"

void setup_camera(game_t *game)
{
    game->game->pos_cam = game->game->player->pos;
    sfView_setCenter(game->game->cam, game->game->pos_cam);
    sfRenderWindow_setView(game->window->window, game->game->cam);
}

void display_world(game_t *game)
{
    int i = 0;

    while (game->game->maps[i] && my_strcmp(game->game->maps[i]->name, game->game->current) != 0)
        i++;
    display_map(game, game->game->maps[i], i);
    display_player(game, i);
    setup_camera(game);
}
