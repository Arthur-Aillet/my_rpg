/*
** EPITECH PROJECT, 2022
** my_rpg_main_2
** File description:
** my_display_png
*/

#include "my_rpg.h"
#include "my_game_struct.h"
#include "player_animation.h"
#include "keyboard.h"
#include "my.h"

void display_pnj(game_t *game)
{
    for (int i = 0; game->game->pnjs[i] != NULL; i++) {
        if (my_strcmp(game->game->pnjs[i]->map_name,
            game->game->current) == 0) {
            sfRenderWindow_drawSprite(game->window->window,
                game->game->pnjs[i]->objet->sprite, NULL);
        }
    }
}
