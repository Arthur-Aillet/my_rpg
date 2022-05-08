/*
** EPITECH PROJECT, 2022
** my_rpg_main_2
** File description:
** init_potions
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my.h"
#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "my_rpg.h"
#include "my_mouse.h"
#include "my_button.h"
#include "keyboard.h"
#include "my_csfml_utils.h"
#include "potions.h"
#include "main_menu.h"
#include "object_creation.h"
#include "inventory_prototypes.h"
#include "inventory_structures.h"

void potion_update_hp(sfText *desc, game_t *game, potion_craft_t *pot, int nb)
{
    if (pot->status == nb) {
        if (is_pressed(pot->l_make, game->window->window,
            game->keys) == true)
            create_potion(game, 4, 5, 7);
        if (is_pressed(pot->m_make, game->window->window,
            game->keys) == true)
            create_potion(game, 2, 3, 6);
        if (is_pressed(pot->s_make, game->window->window,
            game->keys) == true)
            create_potion(game, 1, 1, 5);
        if (is_pressed(pot->r_make, game->window->window,
            game->keys) == true)
            create_potion(game, 3, 10, 4);
        update_button(game->window->window, pot->l_make, game->keys);
        update_button(game->window->window, pot->m_make, game->keys);
        update_button(game->window->window, pot->s_make, game->keys);
        update_button(game->window->window, pot->r_make, game->keys);
        sfRenderWindow_drawText(game->window->window, desc, NULL);
    }
}

void potion_update_st(sfText *desc, game_t *game, potion_craft_t *pot, int nb)
{
    if (pot->status == nb) {
        if (is_pressed(pot->l_make, game->window->window,
            game->keys) == true)
            create_potion(game, 4, 5, 3);
        if (is_pressed(pot->m_make, game->window->window,
            game->keys) == true)
            create_potion(game, 2, 3, 2);
        if (is_pressed(pot->s_make, game->window->window,
            game->keys) == true)
            create_potion(game, 1, 1, 1);
        if (is_pressed(pot->r_make, game->window->window,
            game->keys) == true)
            create_potion(game, 3, 10, 0);
        update_button(game->window->window, pot->l_make, game->keys);
        update_button(game->window->window, pot->m_make, game->keys);
        update_button(game->window->window, pot->s_make, game->keys);
        update_button(game->window->window, pot->r_make, game->keys);
        sfRenderWindow_drawText(game->window->window, desc, NULL);
    }
}

static void init_potion_menu_2(potion_craft_t *potion_menu, game_t *game)
{
    sfText_setString(potion_menu->fire_desc, "An aura of fire \
        \nsurrounds you, killing your \nenemies without mercy \nCost: 2 gel");
    sfText_setFont(potion_menu->fire_desc, FONTG("Ancient.ttf"));
    sfText_setCharacterSize(potion_menu->fire_desc, 35);
    sfText_setPosition(potion_menu->fire_desc, VCF{1460, 300});
    potion_menu->health_desc = sfText_create();
    sfText_setString(potion_menu->health_desc, "R: Regenerate over time \
        \nCost: 3 gel\n\nL: Large\nEnough to heal you from \
        \nthe most dangerous injuries\nCost: 4 gel\n\nM: Medium \
        \nuseful to heal your common wounds\nCost: 2 gel\n\nS: Small \
        \neffective for bruises\nCost: 1 gel");
    sfText_setFont(potion_menu->health_desc, FONTG("Ancient.ttf"));
    sfText_setCharacterSize(potion_menu->health_desc, 27);
    sfText_setPosition(potion_menu->health_desc, VCF{1460, 280});
    potion_menu->stamina_desc = sfText_create();
    sfText_setString(potion_menu->stamina_desc, "R: Regenerate over time \
        \nCost: 3 gel\n\nL: Large\nYou will forget how to sleep\nCost: 4 gel\n \
        \nM: Medium\nExtremely effective\nCost: 2 gel\n\nS: Small \
        \nIt's just coffee\nCost: 1 gel");
    sfText_setFont(potion_menu->stamina_desc, FONTG("Ancient.ttf"));
}

potion_craft_t *init_potion_menu(game_t *game)
{
    potion_craft_t *potion_menu = malloc(sizeof(potion_craft_t));

    potion_menu->status = 0;
    potion_menu->back = create_object("assets/img/craft.jpg",
        VCF{0, 0}, VCF{4, 4});
    potion_menu->stamina =
        create_p(game, "Stamina potion", VCF{810, 430}, VCF{2, 1});
    potion_menu->health =
        create_p(game, "Heal potion", VCF{810, 600}, VCF{2, 1});
    potion_menu->fire = create_p(game, "Fire potion", VCF{810, 770}, VCF{2, 1});
    potion_menu->s_make = create_p(game, "S", VCF{1775, 850}, VCF{0.3, 1});
    potion_menu->m_make = create_p(game, "M", VCF{1685, 850}, VCF{0.3, 1});
    potion_menu->l_make = create_p(game, "L", VCF{1595, 850}, VCF{0.3, 1});
    potion_menu->r_make = create_p(game, "R", VCF{1505, 850}, VCF{0.3, 1});
    potion_menu->fire_make = create_p(game, "Craft", VCF{1640, 850}, VCF{1, 1});
    potion_menu->fire_desc = sfText_create();
    init_potion_menu_2(potion_menu, game);
    sfText_setPosition(potion_menu->stamina_desc, VCF{1460, 270});
    return (potion_menu);
}
