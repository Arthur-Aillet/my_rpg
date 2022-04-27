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

options_menu_t *init_options(game_t *game)
{
    options_menu_t *option = malloc(sizeof(options_menu_t));

    option->status = 2;
    option->keyboard = create_list(VCF{1920 / 2, 540}, game, "Keyboard layout");
    option->keyboard->element = malloc(sizeof(button_t *) * 3);
    for (int i = 0; i != 2; i++) {
        option->keyboard->element[i] = button_create(VCF{1.7, 1.7}, VCF{1920 / 2, 608 + 68 * i}, true);
        button_setup_texture_file(option->keyboard->element[i], (sfIntRect){0, 0, 250, 40}, "assets/img/menu/box_but.jpg");
        button_setup_sounds(option->keyboard->element[i], SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    }
    button_setup_text(option->keyboard->element[0], "Azerty", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->keyboard->element[1], "Qwerty", FONTG("Ancient.ttf"), 40);
    option->keyboard->element[2] = NULL;
    option->back = create_object("assets/img/menu/workshop.jpg", VCF{0, 0}, VCF{1, 1});
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
    init_display_2(option, game);
    init_volume(game, option);
    setup_options_buttons(option, game);
    return (option);
}

void update_options(options_menu_t *option, game_t *game)
{
    update_button(game->window->window, option->controls, game->keys);
    update_button(game->window->window, option->display, game->keys);
    update_button(game->window->window, option->volume, game->keys);
    update_button(game->window->window, option->quit, game->keys);
    update_mouse_cursor(game->window->window, game->mouse);
}

void destroy_options(options_menu_t *option)
{
    destroy_object(option->back);
    destroy_button(option->controls);
    destroy_button(option->display);
    destroy_button(option->volume);
    destroy_button(option->quit);
    sfText_destroy(option->screen_type_title);
    destroy_button(option->screen_type_right);
    destroy_button(option->screen_type_left);
    destroy_object(option->screen_type_background);
    destroy_button(option->screen_type_apply);
    sfText_destroy(option->screen_type_text);
    destroy_list(option->resolution);
    destroy_list(option->frame);
    destroy_list(option->keyboard);
    sfText_destroy(option->vsync_title);
    destroy_check_box(option->vsync);
    sfText_destroy(option->general_title);
    sfText_destroy(option->sfx_title);
    sfText_destroy(option->music_title);
    destroy_slider(option->general);
    destroy_slider(option->sfx);
    destroy_slider(option->music);
    free(option);
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
        if (is_pressed(option->controls, game->window->window, game->keys))
            option->status = 1;
        if (is_pressed(option->display, game->window->window, game->keys))
            option->status = 2;
        if (is_pressed(option->volume, game->window->window, game->keys))
            option->status = 3;
        if (option->status == 1) {
            update_list(option->keyboard, game);
        }
        if (option->status == 2) {
            sfRenderWindow_drawText(game->window->window, option->vsync_title, NULL);
            sfRenderWindow_drawSprite(game->window->window, option->screen_type_background->sprite, NULL);
            sfRenderWindow_drawText(game->window->window, option->screen_type_text, NULL);
            sfRenderWindow_drawText(game->window->window, option->screen_type_title, NULL);
            if (is_pressed(option->screen_type_left, game->window->window, game->keys)) {
                option->screen_type_state = MAX(option->screen_type_state - 1, 0);
                change_window(option);
            }
            if (is_pressed(option->screen_type_right, game->window->window, game->keys)) {
                option->screen_type_state = MIN(option->screen_type_state + 1, 2);
                change_window(option);
            }
            if (is_pressed(option->screen_type_apply, game->window->window, game->keys)) {
                game->window->type = option->screen_type_state;
                sfRenderWindow_destroy(game->window->window);
                create_windows(game->window);
            }
            update_button(game->window->window, option->screen_type_right, game->keys);
            update_button(game->window->window, option->screen_type_left, game->keys);
            update_button(game->window->window, option->screen_type_apply, game->keys);
            update_checkbox_vsync(option->vsync, game);
            update_list(option->resolution, game);
            if (option->resolution->value == true && is_pressed(option->resolution->element[0], game->window->window, game->keys))
                sfRenderWindow_setSize(game->window->window, VCU{1920, 1920 * 9/16});
            if (option->resolution->value == true && is_pressed(option->resolution->element[1], game->window->window, game->keys))
                sfRenderWindow_setSize(game->window->window, VCU{1680, 1680 * 9/16});
            if (option->resolution->value == true && is_pressed(option->resolution->element[2], game->window->window, game->keys))
                sfRenderWindow_setSize(game->window->window, VCU{1440, 1440 * 9/16});
            if (option->resolution->value == true && is_pressed(option->resolution->element[3], game->window->window, game->keys))
                sfRenderWindow_setSize(game->window->window, VCU{1072, 1072 * 9/16});
            if (option->resolution->value == false) {
                update_list_frame(option->frame, game);
            }
        }
        if (option->status == 3) {
            silder_general_manager(game, option);
            silder_music_manager(game, option);
            silder_sfx_manager(game, option);
            sfRenderWindow_drawText(game->window->window, option->general_title, NULL);
            sfRenderWindow_drawText(game->window->window, option->sfx_title, NULL);
            sfRenderWindow_drawText(game->window->window, option->music_title, NULL);
            sfRenderWindow_drawSprite(game->window->window, option->general->back->sprite, NULL);
            sfRenderWindow_drawSprite(game->window->window, option->general->front->sprite, NULL);
            sfRenderWindow_drawSprite(game->window->window, option->general->slider->sprite, NULL);
            sfRenderWindow_drawSprite(game->window->window, option->sfx->back->sprite, NULL);
            sfRenderWindow_drawSprite(game->window->window, option->sfx->front->sprite, NULL);
            sfRenderWindow_drawSprite(game->window->window, option->sfx->slider->sprite, NULL);
            sfRenderWindow_drawSprite(game->window->window, option->music->back->sprite, NULL);
            sfRenderWindow_drawSprite(game->window->window, option->music->front->sprite, NULL);
            sfRenderWindow_drawSprite(game->window->window, option->music->slider->sprite, NULL);
        }
        if (is_pressed(option->quit, game->window->window, game->keys) ||
            game->keys[sfKeyEscape] == PRESS)
            open = 0;
        update_options(option, game);
        sfRenderWindow_display(game->window->window);
    }
    destroy_options(option);
    return 0;
}
