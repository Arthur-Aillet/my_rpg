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
    button_setup_offset(option->vsync_on, VCF{.1, .1}, VCF{.2, .2}, VCF{0, 0});
    button_setup_offset(option->vsync_off, VCF{.1, .1}, VCF{.2, .2}, VCF{0, 0});
}

options_menu_t *init_options(game_t *game)
{
    options_menu_t *option = malloc(sizeof(options_menu_t));

    option->list_value = false;
    option->list_down = button_create(VCF{1, 1}, VCF{1000, 500}, true);
    option->list_up = button_create(VCF{1, 1}, VCF{1000, 500}, true);
    button_setup_texture_file(option->list_down,
        (sfIntRect){0, 0, 250, 40}, "assets/img/menu/list_down.jpg");
    button_setup_texture_file(option->list_up,
        (sfIntRect){0, 0, 250, 40}, "assets/img/menu/list_up.jpg");
    button_setup_text(option->list_down,
        "Resolution", FONTG("Ancient.ttf"), 30);
    button_setup_text(option->list_up,
        "Resolution", FONTG("Ancient.ttf"), 30);
    option->general_back = create_object("assets/img/menu/slider_back.jpg",
        VCF{1920 / 2, 1080 / 2}, VCF{2, 2});
    option->general_front = create_object("assets/img/menu/slider_front.png",
        VCF{1920 / 2 + 5, 1080 / 2 + 5}, VCF{2, 2});
    option->general_slider = create_object("assets/img/menu/slider.png",
        VCF{1920 / 2, 1080 / 2 - 6}, VCF{2, 2});
    sfSprite_setOrigin(option->general_slider->sprite, VCF{sfSprite_getGlobalBounds(option->general_slider->sprite).width / 4, 0});
    option->vsync_status = false;
    option->back = create_object("assets/img/menu/workshop.jpg", VCF{0, 0},
        VCF{1, 1});
    option->title = create_object("assets/img/menu/title.png",
        VCF{480, -50}, VCF{.25, .25});
    option->controls = button_create(VCF{2.1, 1.1}, VCF{960 - 600, 100}, true);
    option->display = button_create(VCF{2.1, 1.1}, VCF{960, 100}, true);
    option->volume = button_create(VCF{2.1, 1.1}, VCF{960 + 600, 100}, true);
    option->quit = button_create(VCF{1, 1}, VCF{1760, 990}, true);
    option->vsync_on = button_create(VCF{1, 1}, VCF{1920 / 2 - 500, 1080 / 2}, false);
    option->vsync_off = button_create(VCF{1, 1}, VCF{1920 / 2 - 500, 1080 / 2}, false);
    button_setup_texture_file(option->vsync_on,
        (sfIntRect){0, 0, 35, 35}, "assets/img/menu/check_on.jpg");
    button_setup_texture_file(option->vsync_off,
        (sfIntRect){0, 0, 35, 35}, "assets/img/menu/check_off.jpg");
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
    update_button_no_display(game->window->window, option->vsync_on, game->keys);
    update_button_no_display(game->window->window, option->vsync_off, game->keys);
    if (option->vsync_status == 0)
        display_button(game->window->window, option->vsync_off);
    else
        display_button(game->window->window, option->vsync_on);
    sfRenderWindow_drawSprite(game->window->window, option->general_back->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window, option->general_front->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window, option->general_slider->sprite, NULL);
    if (option->list_value == true)
        update_button(game->window->window, option->list_up, game->keys);
    else
        update_button(game->window->window, option->list_down, game->keys);
    update_button(game->window->window, option->controls, game->keys);
    update_button(game->window->window, option->display, game->keys);
    update_button(game->window->window, option->volume, game->keys);
    update_button(game->window->window, option->quit, game->keys);
    update_mouse_cursor(game->window->window, game->mouse);
}

void slider_init(object_t *front, object_t *back, object_t *slider, float volume)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(back->sprite);

    sfSprite_setScale(front->sprite, VCF{volume / 100 * 2 , 1 * 2});
    sfSprite_setPosition(slider->sprite, VCF{rect.left + rect.width / 100 * volume, sfSprite_getPosition(slider->sprite).y});
}

void silder_general_manager(game_t *game, options_menu_t *option, bool need_switch)
{
    sfVector2f mouse_pos = get_global_mouse_pos(game->window->window);
    sfFloatRect rect = sfSprite_getGlobalBounds(option->general_back->sprite);

    if (MOUSE_HOVER == true && game->LCLICK)
        need_switch = true;
    if (!game->LCLICK)
        need_switch = false;
    if (need_switch == true) {
        game->general_volume = ((mouse_pos.x - rect.left) * 100 / (rect.width - 5));
        game->general_volume = MAX(0, game->general_volume);
        game->general_volume = MIN(100, game->general_volume);
        sfSprite_setPosition(option->general_slider->sprite, VCF{rect.left + rect.width / 100 * game->general_volume, sfSprite_getPosition(option->general_slider->sprite).y});
        sfSprite_setScale(option->general_front->sprite, VCF{game->general_volume / 100 * 2 , 1 * 2});
    }
}

int option(game_t *game, item_t *items, competences_t *comp)
{
    options_menu_t *option = init_options(game);
    int open = 1;
    bool need_switch = false;

    slider_init(option->general_front, option->general_back, option->general_slider, game->general_volume);
    while (sfRenderWindow_isOpen(game->window->window) && open) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);


        if (is_pressed(option->list_down, game->window->window, game->keys) && option->list_value == true)
            option->list_value = false;
        else if (is_pressed(option->list_up, game->window->window, game->keys) && option->list_value == false)
            option->list_value = true;

        silder_general_manager(game, option, need_switch);

        if (is_pressed(option->vsync_off, game->window->window, game->keys) && option->vsync_status == false)
            option->vsync_status = true;
        else if (is_pressed(option->vsync_on, game->window->window, game->keys) && option->vsync_status == true)
            option->vsync_status = false;
        if (is_pressed(option->quit, game->window->window, game->keys) ||
            game->keys[sfKeyEscape] == PRESS)
            open = 0;
        update_options(option, game);
        sfRenderWindow_display(game->window->window);
    }
    destroy_button(option->quit);
    return 0;
}
