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
#include "inventory_structures.h"

void create_potion(game_t *game)
{
    potion_t *potion = malloc(sizeof(potion_t));
    void (*minigames[2])(game_t *, potion_t *) = {hammer_loop, mortar_loop};
    char *steps = my_strdup("1010");

    potion->current_step = 0;
    potion->numbers_steps = my_strlen(steps);
    potion->difficulty = 10;
    for (int i = 0; potion->current_step != potion->numbers_steps; i++) {
        minigames[steps[i] - '0'](game, potion);
        if (game->keys[sfKeyEscape] == PRESS)
            break;
        potion->current_step += 1;
    }
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
            update_button(game->window->window, potion_menu->l_make, game->keys);
            update_button(game->window->window, potion_menu->m_make, game->keys);
            update_button(game->window->window, potion_menu->s_make, game->keys);
            update_button(game->window->window, potion_menu->r_make, game->keys);
        }
        if (potion_menu->status == 2) {
            update_button(game->window->window, potion_menu->l_make, game->keys);
            update_button(game->window->window, potion_menu->m_make, game->keys);
            update_button(game->window->window, potion_menu->s_make, game->keys);
            update_button(game->window->window, potion_menu->r_make, game->keys);
        }
        if (potion_menu->status == 3) {
            update_button(game->window->window, potion_menu->fire_make, game->keys);
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
