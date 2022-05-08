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
    item_t (*give_pot[12])(item_t, int) = {create_stamina_regen,
        create_stamina_potion_s, create_stamina_potion_m,
        create_stamina_potion_l, create_health_regen, create_molotov,
        create_heal_potion_s, create_heal_potion_m, create_heal_potion_l};

    if (count_item(game->items, GEL) < steps)
        return;
    game->items = consume(game->items, GEL, steps);
    potion->current_step = 0;
    potion->numbers_steps = steps;
    potion->difficulty = difficulty;
    for (; potion->current_step != steps; potion->current_step++)
        if (mortar_loop(game, potion) && game->keys[sfKeyEscape] == PRESS)
            return;
    final_potion = give_pot[type](final_potion, 1);
    game->items = pickup_item(final_potion, game->items);
    free(potion);
}

button_t *create_p(game_t *game, char *name,
    sfVector2f pos, sfVector2f scale)
{
    button_t *potion = button_create(scale, pos, true);

    button_setup_texture_file(potion,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(potion, name, find_font("Ancient.ttf", game->fonts), 40);
    button_setup_sounds(potion, SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_offset(potion, VCF{.1, .1}, VCF{.2, .2}, VCF{0, 0});
    return (potion);
}

void potion_update_fire(game_t *game, potion_craft_t *potion_menu)
{
    if (potion_menu->status == 3) {
        if (is_pressed(potion_menu->fire_make,
            game->window->window, game->keys) == true)
            create_potion(game, 5, 6, 6);
        update_button(game->window->window, potion_menu->fire_make, game->keys);
        sfRenderWindow_drawText(game->window->window,
            potion_menu->fire_desc, NULL);
    }
}

void potion_update(sfText *desc, game_t *game, potion_craft_t *pot, int nb)
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

void potion_main(game_t *game, potion_craft_t *potion, int *open)
{
    set_correct_window_size(game->window);
    sfRenderWindow_clear(game->window->window, sfBlack);
    game->keys = get_keyboard_input(game->keys, game->window->window);
    if (game->keys[sfKeyEscape] == PRESS)
        *open = 0;
    if (is_pressed(potion->stamina, game->window->window, game->keys) == true)
        potion->status = 1;
    if (is_pressed(potion->health, game->window->window, game->keys) == true)
        potion->status = 2;
    if (is_pressed(potion->fire, game->window->window, game->keys) == true)
        potion->status = 3;
    sfRenderWindow_drawSprite(game->window->window, potion->back->sprite, NULL);
    potion_update(potion->health_desc, game, potion, 2);
    potion_update(potion->stamina_desc, game, potion, 1);
    potion_update_fire(game, potion);
    update_button(game->window->window, potion->fire, game->keys);
    update_button(game->window->window, potion->health, game->keys);
    update_button(game->window->window, potion->stamina, game->keys);
    update_mouse_cursor(game->window->window, game->mouse);
    sfRenderWindow_display(game->window->window);
}

void potion_loop(game_t *game)
{
    potion_craft_t *potion_menu = init_potion_menu(game);
    sfView *current = sfView_copy(sfRenderWindow_getView(game->window->window));
    sfView *last = sfView_copy(current);
    int open = 1;

    sfView_setCenter(current, VCF{1920 / 2, 1080 / 2});
    sfRenderWindow_setView(game->window->window, current);
    while (sfRenderWindow_isOpen(game->window->window) && open)
        potion_main(game, potion_menu, &open);
    sfRenderWindow_setView(game->window->window, last);
    sfView_destroy(last);
    sfView_destroy(current);
}
