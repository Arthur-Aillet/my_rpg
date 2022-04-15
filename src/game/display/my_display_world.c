/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_WORLD_C
** File description:
** my_display_world
*/

#include "my_rpg.h"

void display_world(game_t *game)
{
    int i = 0;

    while (game->game->maps[i] && my_strcmp(game->game->maps[i]->name, game->game->current) != 0)
        i++;
    display_map(game, game->game->maps[i], i);
    display_player(game, i);
}
