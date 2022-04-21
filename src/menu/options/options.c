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
    button_setup_text(option->new_game, "New game", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->options, "Options", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->quit, "Quit", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->continue_game,
        "Continue game", FONTG("Ancient.ttf"), 40);
    button_setup_sounds(option->new_game,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_sounds(option->continue_game,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_sounds(option->options,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_sounds(option->quit,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_offset(option->new_game, VCF{-.09, .2}, VCF{.17, .06});
    button_setup_offset(option->continue_game, VCF{-.09, .2}, VCF{.17, .06});
    button_setup_offset(option->options, VCF{-.09, .2}, VCF{.17, .06});
    button_setup_offset(option->quit, VCF{-.09, .2}, VCF{.17, .06});
}

options_menu_t *init_options(game_t *game)
{
    options_menu_t *option = malloc(sizeof(options_menu_t));

    option->back = create_object("assets/img/menu/focus.jpg", VCF{0, -30},
        VCF{1, 1});
    option->title = create_object("assets/img/menu/title.png",
        VCF{480, -50}, VCF{.25, .25});
    option->new_game = button_create(VCF{2.2, 1}, VCF{960, 412}, true);
    option->continue_game = button_create(VCF{2.2, 1}, VCF{960, 540}, true);
    option->options = button_create(VCF{2.2, 1}, VCF{960, 668}, true);
    option->quit = button_create(VCF{2.2, 1}, VCF{960, 796}, true);
    button_setup_texture_file(option->new_game,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_texture_file(option->continue_game,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_texture_file(option->options,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_texture_file(option->quit,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    setup_options_buttons(option, game);
    return (option);
}

void update_options(options_menu_t *option, game_t *game)
{
    //sfRenderWindow_drawSprite(game->window->window, option->back->sprite, NULL);
    //sfRenderWindow_drawSprite(game->window->window, option->title->sprite, NULL);
    update_button(game->window->window, option->new_game, game->keys);
    update_button(game->window->window, option->continue_game, game->keys);
    update_button(game->window->window, option->options, game->keys);
    update_button(game->window->window, option->quit, game->keys);
    update_mouse_cursor(game->window->window, game->mouse);
    sfRenderWindow_display(game->window->window);
}

int option(game_t *game, item_t *items, competences_t *comp)
{
    options_menu_t *option = init_main_menu(game);
    int open = 1;

    while (sfRenderWindow_isOpen(game->window->window) && open) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);
        if (is_pressed(option->quit, game->window->window, game->keys))
            open = 0;
        if (game->keys[sfKeyEscape] == PRESS)
            inventory(game->window->window, items, comp, game->keys);
        if (game->keys[sfKeyP] == PRESS)
            potion_loop(game);
        if (is_pressed(option->new_game, game->window->window, game->keys))
            game_loop(game);
        update_options(option, game);
    }
    destroy_button(option->quit);
    return 0;
}
