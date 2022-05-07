/*
** EPITECH PROJECT, 2022
** rpg - menu displays
** File description:
** functions to display the different pages
*/

#include "inventory_structures.h"
#include "inventory_prototypes.h"
#include "my_game_struct.h"
#include <stdio.h>

void disp_inv(backgrounds_t bgs)
{
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[0]->sprite, NULL);
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[1]->sprite, NULL);
    draw_items(bgs.window, bgs.items, bgs.text);
}

void disp_map(backgrounds_t bgs)
{
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[0]->sprite, NULL);
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[2]->sprite, NULL);
};

void disp_cmp(backgrounds_t bgs)
{
    sfRenderWindow_clear(bgs.window, sfBlack);
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[0]->sprite, NULL);
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[3]->sprite, NULL);
    draw_competences(bgs.window, bgs.comp);
    draw_descriptions(bgs.window, bgs.comp, bgs.text.text);
}

void set_view_inv(game_t *game)
{
    sfView_setCenter(game->game->cam, VCF {970, 540});
    sfRenderWindow_setView(game->window->window, game->game->cam);
}