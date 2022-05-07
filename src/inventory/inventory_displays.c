/*
** EPITECH PROJECT, 2022
** rpg - menu displays
** File description:
** functions to display the different pages
*/

#include "inventory_structures.h"
#include "inventory_prototypes.h"
#include "my_game_struct.h"
#include "my.h"
#include <stdio.h>

void disp_inv(backgrounds_t bgs)
{
    sfRenderWindow_clear(bgs.window, sfBlack);
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[0]->sprite, NULL);
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[1]->sprite, NULL);
    draw_items(bgs.window, bgs.items, bgs.text);
}

void display_stats(backgrounds_t bgs)
{
    sfText_setPosition(bgs.text.text, VCF {1500, 200});
    sfText_setString(bgs.text.text, "max health     :\nmax stamina    :\n"
        "speed          :\ndash           :\nxp to next lvl :\n");
    sfRenderWindow_drawText(bgs.window, bgs.text.text, NULL);
    sfText_setPosition(bgs.text.text, VCF {1700, 200});
    sfText_setString(bgs.text.text, my_itoa((int) bgs.player->max_health));
    sfRenderWindow_drawText(bgs.window, bgs.text.text, NULL);
    sfText_setPosition(bgs.text.text, VCF {1700, 230});
    sfText_setString(bgs.text.text, my_itoa((int) bgs.player->max_stamina));
    sfRenderWindow_drawText(bgs.window, bgs.text.text, NULL);
    sfText_setPosition(bgs.text.text, VCF {1700, 260});
    sfText_setString(bgs.text.text, my_itoa((int) bgs.player->move_spd));
    sfRenderWindow_drawText(bgs.window, bgs.text.text, NULL);
    sfText_setPosition(bgs.text.text, VCF {1700, 290});
    sfText_setString(bgs.text.text, my_itoa((int) bgs.player->dash >= 0));
    sfRenderWindow_drawText(bgs.window, bgs.text.text, NULL);
    sfText_setPosition(bgs.text.text, VCF {1700, 310});
    sfText_setString(bgs.text.text, my_itoa((int) 1000 - bgs.player->exp));
    sfRenderWindow_drawText(bgs.window, bgs.text.text, NULL);
}

void disp_map(backgrounds_t bgs)
{
    sfRenderWindow_clear(bgs.window, sfBlack);
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[0]->sprite, NULL);
    sfRenderWindow_drawSprite(bgs.window, bgs.pages[2]->sprite, NULL);
    display_stats(bgs);
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