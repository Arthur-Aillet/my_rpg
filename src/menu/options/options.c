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
#include "my_math.h"
#include "my_rpg.h"
#include "my_mouse.h"
#include "my_button.h"
#include "keyboard.h"
#include "my_csfml_utils.h"
#include "my.h"

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

void init_options_2(game_t *game, options_menu_t *option)
{
    option->back = create_object("assets/img/menu/workshop.jpg",
        VCF{0, 0}, VCF{1, 1});
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
    init_display(game, option);
    init_volume(game, option);
    setup_options_buttons(option, game);
}

options_menu_t *init_options(game_t *game)
{
    options_menu_t *option = malloc(sizeof(options_menu_t));

    option->status = 2;
    option->keyboard = create_list(VCF{960, 540}, game, "Keyboard layout");
    option->keyboard->element = malloc(sizeof(button_t *) * 3);
    for (int i = 0; i != 2; i++) {
        option->keyboard->element[i] = button_create(
            VCF{1.7, 1.7}, VCF{960, 608 + 68 * i}, true);
        button_setup_texture_file(option->keyboard->element[i],
            (sfIntRect){0, 0, 250, 40}, "assets/img/menu/box_but.jpg");
        button_setup_sounds(option->keyboard->element[i],
            SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    }
    button_setup_text(option->keyboard->element[0],
        "Azerty", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->keyboard->element[1],
        "Qwerty", FONTG("Ancient.ttf"), 40);
    option->keyboard->element[2] = NULL;
    init_options_2(game, option);
    return (option);
}

void update_options(options_menu_t *option, game_t *game, int *open)
{
    if (is_pressed(option->controls, game->window->window, game->keys))
        option->status = 1;
    if (is_pressed(option->display, game->window->window, game->keys))
        option->status = 2;
    if (is_pressed(option->volume, game->window->window, game->keys))
        option->status = 3;
    if (option->status == 1)
        update_list(option->keyboard, game);
    if (option->status == 2)
        update_display(game, option);
    if (option->status == 3)
        update_volume(game, option);
    if (is_pressed(option->quit, game->window->window, game->keys) ||
        game->keys[sfKeyEscape] == PRESS)
        *open = 0;
    update_button(game->window->window, option->controls, game->keys);
    update_button(game->window->window, option->display, game->keys);
    update_button(game->window->window, option->volume, game->keys);
    update_button(game->window->window, option->quit, game->keys);
    update_mouse_cursor(game->window->window, game->mouse);
}

int option(game_t *game)
{
    options_menu_t *option = init_options(game);
    int open = 1;

    slider_init(option->general, game->general_volume);
    slider_init(option->sfx, game->sfx_volume);
    slider_init(option->music, game->music_volume);
    option->vsync->status = game->window->vsync;
    while (sfRenderWindow_isOpen(game->window->window) && open) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);
        sfRenderWindow_drawSprite(game->window->window, option->back->sprite, NULL);
        update_options(option, game, &open);
        sfRenderWindow_display(game->window->window);
    }
    destroy_options(option);
    return 0;
}
