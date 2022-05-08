/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** potion_loop
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

void create_potion(game_t *game, int steps, int difficulty, int type)
{
    potion_t *potion = malloc(sizeof(potion_t));
    item_t final_potion;
    item_t (*give_pot[12])(item_t, int) = {create_stamina_regen, create_stamina_potion_s,
        create_stamina_potion_m, create_stamina_potion_l, create_health_regen,
        create_molotov, create_heal_potion_s, create_heal_potion_m,
        create_heal_potion_l};

    if (count_item(game->items, GEL) < steps)
        return;
    game->items = consume(game->items, GEL, steps);
    potion->current_step = 0;
    potion->numbers_steps = steps;
    potion->difficulty = difficulty;
    for (; potion->current_step != steps; potion->current_step++) {
         mortar_loop(game, potion);
        if (game->keys[sfKeyEscape] == PRESS)
            return;
    }
    final_potion = give_pot[type](final_potion, 1);
    game->items = pickup_item(final_potion, game->items);
    free(potion);
}

button_t *create_potion_button(game_t *game, char *name, sfVector2f pos, sfVector2f scale)
{
    button_t *potion = button_create(scale, pos, true);

    button_setup_texture_file(potion,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(potion, name, find_font("Ancient.ttf", game->fonts), 40);
    button_setup_sounds(potion, SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_offset(potion, VCF{.1, .1}, VCF{.2, .2}, VCF{0, 0});
    return (potion);
}

potion_craft_t *init_potion_menu(game_t *game)
{
    potion_craft_t *potion_menu = malloc(sizeof(potion_craft_t));

    potion_menu->status = 0;
    potion_menu->back = create_object("assets/img/craft.jpg", VCF{0, 0}, VCF{4, 4});
    potion_menu->stamina = create_potion_button(game, "Stamina potion", VCF{1920 / 2 - 150, 540 - 170 + 60}, VCF{2, 1});
    potion_menu->health = create_potion_button(game, "Heal potion", VCF{1920 / 2 - 150, 540 + 60}, VCF{2, 1});
    potion_menu->fire = create_potion_button(game, "Fire potion", VCF{1920 / 2 - 150, 540 + 170 + 60}, VCF{2, 1});
    potion_menu->s_make = create_potion_button(game, "S", VCF{1920 / 2 + 455 + 90 * 4, 850}, VCF{0.3, 1});
    potion_menu->m_make = create_potion_button(game, "M", VCF{1920 / 2 + 455 + 90 * 3, 850}, VCF{0.3, 1});
    potion_menu->l_make = create_potion_button(game, "L", VCF{1920 / 2 + 455 + 90 * 2, 850}, VCF{0.3, 1});
    potion_menu->r_make = create_potion_button(game, "R", VCF{1920 / 2 + 455 + 90, 850}, VCF{0.3, 1});
    potion_menu->fire_make = create_potion_button(game, "Craft", VCF{1920 / 2 + 430 + 250, 850}, VCF{1, 1});
    potion_menu->fire_desc = sfText_create();
    sfText_setString(potion_menu->fire_desc, "An aura of fire\nsurrounds you, killing your\nenemies without mercy\nCost: 5 gel");
    sfText_setFont(potion_menu->fire_desc, FONTG("Ancient.ttf"));
    sfText_setCharacterSize(potion_menu->fire_desc, 35);
    sfText_setPosition(potion_menu->fire_desc, VCF{1920 / 2 + 500, 300});
    potion_menu->health_desc = sfText_create();
    sfText_setString(potion_menu->health_desc, "R: Regenerate over time\nCost: 3 gel\n\nL: Large\nEnough to heal you from\nthe most dangerous injuries\nCost: 4 gel\n\nM: Medium\nuseful to heal your common wounds\nCost: 2 gel\n\nS: Small\neffective for bruises\nCost: 1 gel");
    sfText_setFont(potion_menu->health_desc, FONTG("Ancient.ttf"));
    sfText_setCharacterSize(potion_menu->health_desc, 27);
    sfText_setPosition(potion_menu->health_desc, VCF{1920 / 2 + 500, 280});
    potion_menu->stamina_desc = sfText_create();
    sfText_setString(potion_menu->stamina_desc, "R: Regenerate over time\nCost: 3 gel\n\nL: Large\nYou will forget how to sleep\nCost: 4 gel\n\nM: Medium\nExtremely effective\nCost: 2 gel\n\nS: Small\nIt's just coffee\nCost: 1 gel");
    sfText_setFont(potion_menu->stamina_desc, FONTG("Ancient.ttf"));
    sfText_setPosition(potion_menu->stamina_desc, VCF{1920 / 2 + 500, 270});
    return (potion_menu);
}

void potion_loop(game_t *game)
{
    potion_craft_t *potion_menu = init_potion_menu(game);
    sfView *current = sfView_copy(sfRenderWindow_getView(game->window->window));
    sfView *last = sfView_copy(current);
    int open = 1;

    sfView_setCenter(current, VCF{1920 / 2, 1080 / 2});
    sfRenderWindow_setView(game->window->window, current);
    while (sfRenderWindow_isOpen(game->window->window) && open) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);
        if (game->keys[sfKeyEscape] == PRESS)
            open = 0;
        if (is_pressed(potion_menu->stamina, game->window->window, game->keys) == true)
            potion_menu->status = 1;
        if (is_pressed(potion_menu->health, game->window->window, game->keys) == true)
            potion_menu->status = 2;
        if (is_pressed(potion_menu->fire, game->window->window, game->keys) == true)
            potion_menu->status = 3;
        sfRenderWindow_drawSprite(game->window->window, potion_menu->back->sprite, NULL);
        if (potion_menu->status == 1) {
            if (is_pressed(potion_menu->l_make, game->window->window, game->keys) == true)
                create_potion(game, 4, 5, 3);
            if (is_pressed(potion_menu->m_make, game->window->window, game->keys) == true)
                create_potion(game, 2, 3, 2);
            if (is_pressed(potion_menu->s_make, game->window->window, game->keys) == true)
                create_potion(game, 1, 1, 1);
            if (is_pressed(potion_menu->r_make, game->window->window, game->keys) == true)
                create_potion(game, 3, 10, 0);
            update_button(game->window->window, potion_menu->l_make, game->keys);
            update_button(game->window->window, potion_menu->m_make, game->keys);
            update_button(game->window->window, potion_menu->s_make, game->keys);
            update_button(game->window->window, potion_menu->r_make, game->keys);
            sfRenderWindow_drawText(game->window->window, potion_menu->stamina_desc, NULL);
        }
        if (potion_menu->status == 2) {
            if (is_pressed(potion_menu->l_make, game->window->window, game->keys) == true)
                create_potion(game, 4, 5, 9);
            if (is_pressed(potion_menu->m_make, game->window->window, game->keys) == true)
                create_potion(game, 2, 3, 8);
            if (is_pressed(potion_menu->s_make, game->window->window, game->keys) == true)
                create_potion(game, 1, 1, 7);
            if (is_pressed(potion_menu->r_make, game->window->window, game->keys) == true)
                create_potion(game, 3, 10, 5);
            update_button(game->window->window, potion_menu->l_make, game->keys);
            update_button(game->window->window, potion_menu->m_make, game->keys);
            update_button(game->window->window, potion_menu->s_make, game->keys);
            update_button(game->window->window, potion_menu->r_make, game->keys);
            sfRenderWindow_drawText(game->window->window, potion_menu->health_desc, NULL);
        }
        if (potion_menu->status == 3) {
            if (is_pressed(potion_menu->fire_make, game->window->window, game->keys) == true)
                create_potion(game, 5, 6, 6);
            update_button(game->window->window, potion_menu->fire_make, game->keys);
            sfRenderWindow_drawText(game->window->window, potion_menu->fire_desc, NULL);
        }
        update_button(game->window->window, potion_menu->fire, game->keys);
        update_button(game->window->window, potion_menu->health, game->keys);
        update_button(game->window->window, potion_menu->stamina, game->keys);
        update_mouse_cursor(game->window->window, game->mouse);
        sfRenderWindow_display(game->window->window);
    }
    sfRenderWindow_setView(game->window->window, last);
    sfView_destroy(last);
    sfView_destroy(current);
}
