/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display
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
#include "inventory_structures.h"

void change_window(options_menu_t *option)
{
    if (option->screen_type_state == 0)
        sfText_setString(option->screen_type_text, "Windowed");
    if (option->screen_type_state == 1)
        sfText_setString(option->screen_type_text, "Borderless");
    if (option->screen_type_state == 2)
        sfText_setString(option->screen_type_text, "Fullscreen");
}

void init_display(game_t *game, options_menu_t *option)
{
    sfFloatRect textRect;

    option->screen_type_state = game->window->type;
    option->screen_type_title = sfText_create();
    option->screen_type_text = sfText_create();
    sfText_setFont(option->screen_type_title, FONTG("Ancient.ttf"));
    sfText_setFont(option->screen_type_text, FONTG("Ancient.ttf"));
    sfText_setString(option->screen_type_title, "Screen type:");
    change_window(option);
    sfText_setCharacterSize(option->screen_type_title, 50);
    sfText_setCharacterSize(option->screen_type_text, 40);
    textRect = sfText_getGlobalBounds(option->screen_type_text);
    sfText_setOrigin(option->screen_type_text, VCF{textRect.left + textRect.width / 2, textRect.top + textRect.height / 2});
    sfText_setPosition(option->screen_type_text, VCF{1920 / 2, 300 + 80.0});
    textRect = sfText_getGlobalBounds(option->screen_type_title);
    sfText_setOrigin(option->screen_type_title, VCF{textRect.left + textRect.width / 2, textRect.top + textRect.height / 2});
    sfText_setPosition(option->screen_type_title, VCF{1920 / 2 , 230 + 80.0});
    option->screen_type_right = button_create(VCF{2.5, 2.5}, VCF{1920 / 2 + 250, 300 + 80.0}, false);
    button_setup_sounds(option->screen_type_right, SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    option->screen_type_left = button_create(VCF{2.5, 2.5}, VCF{1920 / 2 - 250, 300 + 80.0}, false);
    button_setup_sounds(option->screen_type_left, SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_texture_file(option->screen_type_right, (sfIntRect){0, 0, 27, 27}, "assets/img/menu/right_arrow.png");
    button_setup_texture_file(option->screen_type_left, (sfIntRect){0, 0, 27, 27}, "assets/img/menu/left_arrow.png");
    option->screen_type_background = create_object("assets/img/menu/box.jpg", VCF{1920 / 2 - (250 * 1.5) / 2, 300 + 80.0 - (40 * 1.5) / 2}, VCF{1.5, 1.5});
    option->screen_type_apply = button_create(VCF{.75, .75}, VCF{1920 / 2, 398 + 80.0}, true);
    button_setup_sounds(option->screen_type_apply, SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_texture_file(option->screen_type_apply, (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(option->screen_type_apply, "Apply", FONTG("Ancient.ttf"), 40);
    button_setup_offset(option->screen_type_apply, VCF{.05, .05}, VCF{.1, .1}, VCF{0, 2});
}

void init_display_2(options_menu_t *option, game_t *game)
{
    sfFloatRect textRect;

    option->resolution = create_list(VCF{1920 / 2, 500 + 80.0}, game,
        "Screen resolution");
    option->resolution->element = malloc(sizeof(button_t *) * 5);
    for (int i = 0; i != 4; i++) {
        option->resolution->element[i] = button_create(VCF{1.7, 1.7}, VCF{1920 / 2, 580 + 68 + 68 * i}, true);
        button_setup_texture_file(option->resolution->element[i], (sfIntRect){0, 0, 250, 40}, "assets/img/menu/box_but.jpg");
        button_setup_sounds(option->resolution->element[i], SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    }
    button_setup_text(option->resolution->element[0], "1920x1080", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->resolution->element[1], "1680x945", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->resolution->element[2], "1440x810", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->resolution->element[3], "1072x603", FONTG("Ancient.ttf"), 40);
    option->resolution->element[4] = NULL;
    option->frame = create_list(VCF{1920 / 2, 680}, game, "Frame rate");
    option->frame->element = malloc(sizeof(button_t *) * 6);
    for (int i = 0; i != 5; i++) {
        option->frame->element[i] = button_create(VCF{1.7, 1.7}, VCF{1920 / 2, 680 + 68 + 68 * i}, true);
        button_setup_texture_file(option->frame->element[i], (sfIntRect){0, 0, 250, 40}, "assets/img/menu/box_but.jpg");
        button_setup_sounds(option->frame->element[i], SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    }
    button_setup_text(option->frame->element[0], "240", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->frame->element[1], "144", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->frame->element[2], "75", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->frame->element[3], "60", FONTG("Ancient.ttf"), 40);
    button_setup_text(option->frame->element[4], "30", FONTG("Ancient.ttf"), 40);
    option->frame->element[5] = NULL;
    option->vsync_title = sfText_create();
    sfText_setFont(option->vsync_title, FONTG("Ancient.ttf"));
    sfText_setString(option->vsync_title, "Vsync");
    sfText_setCharacterSize(option->vsync_title, 50);
    textRect = sfText_getGlobalBounds(option->vsync_title);
    sfText_setOrigin(option->vsync_title, VCF{textRect.left +
        textRect.width / 2, textRect.top + textRect.height / 2});
    sfText_setPosition(option->vsync_title, VCF{1920 / 2, 690 + 80.0});
    option->vsync = create_check(VCF{1920 / 2 - 100, 690 + 80.0}, game);
}

void update_list_frame(list_t *list, game_t *game)
{
    if (is_pressed(list->down, game->window->window, game->keys) && list->value == true)
        list->value = false;
    else if (is_pressed(list->up, game->window->window, game->keys) && list->value == false)
        list->value = true;
    if (list->value == true) {
        update_button(game->window->window, list->up, game->keys);
        for (int i = 0; list->element[i] != NULL; i++) {
            update_button(game->window->window, list->element[i], game->keys);
            if (is_pressed(list->element[i], game->window->window, game->keys)) {
                sfRenderWindow_setFramerateLimit(game->window->window, my_getnbr(sfText_getString(list->element[i]->text.text)));
                game->window->framerate = my_getnbr(sfText_getString(list->element[i]->text.text));
            }
        }
    } else
        update_button(game->window->window, list->down, game->keys);
}
