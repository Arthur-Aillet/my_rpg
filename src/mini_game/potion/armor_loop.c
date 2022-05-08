/*
** EPITECH PROJECT, 2022
** my_rpg_main_2
** File description:
** armor_loop
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
#include "potions.h"
#include "my_math.h"

static int loop_anvil(game_t *game, potion_t *fake_potion)
{
    for (; fake_potion->current_step != 3; fake_potion->current_step++)
        if (hammer_loop(game, fake_potion)
            && game->keys[sfKeyEscape] == PRESS)
        return 1;
    return 0;
}

static void get_armor(game_t *game, item_t item)
{
    potion_t *fake_potion;

    if (game->E == 2 && my_strcmp(game->game->current, "house") == 0 &&
        dist_two_points(game->game->player->pos, VCF{960, 400}) <= 200) {
        fake_potion = malloc(sizeof(potion_t));
        fake_potion->current_step = 0;
        fake_potion->numbers_steps = 3;
        fake_potion->difficulty = 4;
        if (loop_anvil(game, fake_potion) == 1)
            return;
        item = create_helmet(item, 1);
        pickup_item(item, game->items);
        item = create_cuirass(item, 1);
        pickup_item(item, game->items);
        item = create_breeches(item, 1);
        pickup_item(item, game->items);
        item = create_sabaton(item, 1);
        pickup_item(item, game->items);
    }
}

void launch_craft(game_t *game)
{
    item_t item;

    if (my_strcmp(game->game->current, "house") == 0 &&
        dist_two_points(game->game->player->pos, VCF{1855, 350}) <= 200) {
        sfSprite_setPosition(game->game->player->craft_box->sprite,
            VCF{1855 - 24, 350 - 23});
        sfRenderWindow_drawSprite(game->window->window,
            game->game->player->craft_box->sprite, NULL);
    }
    if (game->E == 2 && my_strcmp(game->game->current, "house") == 0 &&
        dist_two_points(game->game->player->pos, VCF{1855, 350}) <= 200)
        potion_loop(game);
    if (my_strcmp(game->game->current, "house") == 0 &&
        dist_two_points(game->game->player->pos, VCF{960, 400}) <= 200) {
        sfSprite_setPosition(game->game->player->craft_box->sprite,
            VCF{960 - 24, 400 - 23});
        sfRenderWindow_drawSprite(game->window->window,
            game->game->player->craft_box->sprite, NULL);
    }
    get_armor(game, item);
}
