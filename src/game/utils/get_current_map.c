/*
** EPITECH PROJECT, 2022
** GET_CURRENT_MAP_C
** File description:
** get_current_map
*/

#include "my_rpg.h"
#include "my.h"

int get_current_map(game_t *game)
{
    int i = 0;

    while (my_strcmp(game->game->maps[i]->name, game->game->current) != 0)
        i++;
    return i;
}
