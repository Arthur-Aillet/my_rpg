/*
** EPITECH PROJECT, 2022
** rpg - menu displays
** File description:
** functions to display the different pages
*/

#include "inventory_structures.h"
#include "menu_prototypes.h"
#include <stdio.h>

void disp_inv(struct backgrounds bgs)
{
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[0]->sprite, NULL);
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[1]->sprite, NULL);
    draw_items(bgs.window, bgs.items, bgs.text);
}

void disp_map(struct backgrounds bgs)
{
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[0]->sprite, NULL);
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[2]->sprite, NULL);
};

void disp_cmp(struct backgrounds bgs)
{
    sfRenderWindow_clear(bgs.window, sfBlack);
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[0]->sprite, NULL);
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[3]->sprite, NULL);
    draw_competences(bgs.window, bgs.comp);
}
