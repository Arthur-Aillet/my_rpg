/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** options
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>

#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "main_menu.h"
#include "my_rpg.h"
#include "my_mouse.h"
#include "my_button.h"
#include "keyboard.h"
#include "my_csfml_utils.h"
#include "potions.h"
#include "inventory_structures.h"

void setup_options_buttons(options_menu_t *option, game_t *game)
{
    button_setup_text(option->controls, "Control options", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->volume, "Volume options", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->quit, "Retrun", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->display,
        "Display options", FONTG("Ancient.ttf"), 40);
    button_setup_sounds(option->controls,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_sounds(option->display,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_sounds(option->volume,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_sounds(option->quit,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_offset(option->controls, VCF{-.09, .2}, VCF{.1, .06}, VCF{0, 0});
    button_setup_offset(option->display, VCF{-.09, .2}, VCF{.1, .06}, VCF{0, 0});
    button_setup_offset(option->volume, VCF{-.09, .2}, VCF{.1, .06}, VCF{0, 0});
    button_setup_offset(option->quit, VCF{.05, .05}, VCF{.1, .1}, VCF{0, 0});
}

options_menu_t *init_options(game_t *game)
{
    options_menu_t *option = malloc(sizeof(options_menu_t));

    option->back = create_object("assets/img/menu/workshop.jpg", VCF{0, 0},
        VCF{1, 1});
    option->title = create_object("assets/img/menu/title.png",
        VCF{480, -50}, VCF{.25, .25});
    option->controls = button_create(VCF{2.1, 1.1}, VCF{960 - 600, 100}, true);
    option->display = button_create(VCF{2.1, 1.1}, VCF{960, 100}, true);
    option->volume = button_create(VCF{2.1, 1.1}, VCF{960 + 600, 100}, true);
    option->quit = button_create(VCF{1, 1}, VCF{1760, 990}, true);
    button_setup_texture_file(option->controls,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_texture_file(option->display,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_texture_file(option->volume,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_texture_file(option->quit,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    setup_options_buttons(option, game);
    return (option);
}

void update_options(options_menu_t *option, game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, option->back->sprite, NULL);
    //sfRenderWindow_drawSprite(game->window->window, option->title->sprite, NULL);
    update_button(game->window->window, option->controls, game->keys);
    update_button(game->window->window, option->display, game->keys);
    update_button(game->window->window, option->volume, game->keys);
    update_button(game->window->window, option->quit, game->keys);
    update_mouse_cursor(game->window->window, game->mouse);
    sfRenderWindow_display(game->window->window);
}

int option(game_t *game, item_t *items, competences_t *comp)
{
    options_menu_t *option = init_options(game);
    int open = 1;

    while (sfRenderWindow_isOpen(game->window->window) && open) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);
        if (is_pressed(option->quit, game->window->window, game->keys) ||
            game->keys[sfKeyEscape] == PRESS)
            open = 0;
        update_options(option, game);
    }
    destroy_button(option->quit);
    return 0;
}
