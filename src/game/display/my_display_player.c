/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_PLAYER_C
** File description:
** my_display_player
*/

#include "my_rpg.h"

void display_player(game_t *game, int i)
{
    sfSprite_setPosition(game->game->player->sp_p, game->game->player->pos);
    sfRenderWindow_drawSprite(game->window->window, game->game->player->sp_p, NULL);
}
