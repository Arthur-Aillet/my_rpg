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

static void init_display_5(options_menu_t *op, game_t *game)
{
    sfFloatRect textRect;

    button_setup_text(op->frame->element[0], "240", FONTG("Ancient.ttf"), 40);
    button_setup_text(op->frame->element[1], "144", FONTG("Ancient.ttf"), 40);
    button_setup_text(op->frame->element[2], "75", FONTG("Ancient.ttf"), 40);
    button_setup_text(op->frame->element[3], "60", FONTG("Ancient.ttf"), 40);
    button_setup_text(op->frame->element[4], "30", FONTG("Ancient.ttf"), 40);
    op->frame->element[5] = NULL;
    op->vsync_title = sfText_create();
    sfText_setFont(op->vsync_title, FONTG("Ancient.ttf"));
    sfText_setString(op->vsync_title, "Vsync");
    sfText_setCharacterSize(op->vsync_title, 50);
    textRect = sfText_getGlobalBounds(op->vsync_title);
    sfText_setOrigin(op->vsync_title, VCF{textRect.left +
        textRect.width / 2, textRect.top + textRect.height / 2});
    sfText_setPosition(op->vsync_title, VCF{960, 770});
    op->vsync = create_check(VCF{860, 770}, game);
}

static void init_display_4(options_menu_t *op, game_t *game)
{
    button_setup_text(op->resolution->element[2],
        "1440x810", FONTG("Ancient.ttf"), 40);
    button_setup_text(op->resolution->element[3],
        "1072x603", FONTG("Ancient.ttf"), 40);
    op->resolution->element[4] = NULL;
    op->frame = create_list(VCF{960, 680}, game, "Frame rate");
    op->frame->element = malloc(sizeof(button_t *) * 6);
    for (int i = 0; i != 5; i++) {
        op->frame->element[i] = button_create(VCF{1.7, 1.7},
            VCF{960, 680 + 68 + 68 * i}, true);
        button_setup_texture_file(op->frame->element[i],
            (sfIntRect){0, 0, 250, 40}, "assets/img/menu/box_but.jpg");
        button_setup_sounds(op->frame->element[i],
            SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    }
    init_display_5(op, game);
}

static void init_display_3(options_menu_t *op, game_t *game)
{
    button_setup_offset(op->screen_type_apply,
        VCF{.05, .05}, VCF{.1, .1}, VCF{0, 2});
    op->resolution = create_list(VCF{960, 500 + 80.0}, game,
        "Screen resolution");
    op->resolution->element = malloc(sizeof(button_t *) * 5);
    for (int i = 0; i != 4; i++) {
        op->resolution->element[i] = button_create(VCF{1.7, 1.7},
            VCF{960, 648 + 68 * i}, true);
        button_setup_texture_file(op->resolution->element[i],
            (sfIntRect){0, 0, 250, 40}, "assets/img/menu/box_but.jpg");
        button_setup_sounds(op->resolution->element[i],
            SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    }
    button_setup_text(op->resolution->element[0],
        "1920x1080", FONTG("Ancient.ttf"), 40);
    button_setup_text(op->resolution->element[1],
        "1680x945", FONTG("Ancient.ttf"), 40);
    init_display_4(op, game);
}

static void init_display_2(game_t *game, options_menu_t *op)
{
    op->screen_type_right = button_create(VCF{2.5, 2.5}, VCF{1210, 380}, false);
    button_setup_sounds(op->screen_type_right,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    op->screen_type_left = button_create(VCF{2.5, 2.5}, VCF{710, 380}, false);
    button_setup_sounds(op->screen_type_left,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_texture_file(op->screen_type_right,
        (sfIntRect){0, 0, 27, 27}, "assets/img/menu/right_arrow.png");
    button_setup_texture_file(op->screen_type_left,
        (sfIntRect){0, 0, 27, 27}, "assets/img/menu/left_arrow.png");
    op->screen_type_background = create_object("assets/img/menu/box.jpg",
        VCF{773, 350}, VCF{1.5, 1.5});
    op->screen_type_apply = button_create(VCF{.75, .75}, VCF{960, 478}, true);
    button_setup_sounds(op->screen_type_apply,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_texture_file(op->screen_type_apply,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(op->screen_type_apply, "Apply", FONTG("Ancient.ttf"), 40);
    init_display_3(op, game);
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
    sfText_setOrigin(option->screen_type_text, VCF{textRect.left +
        textRect.width / 2, textRect.top + textRect.height / 2});
    sfText_setPosition(option->screen_type_text, VCF{960, 380});
    textRect = sfText_getGlobalBounds(option->screen_type_title);
    sfText_setOrigin(option->screen_type_title, VCF{textRect.left +
        textRect.width / 2, textRect.top + textRect.height / 2});
    sfText_setPosition(option->screen_type_title, VCF{960 , 310});
    init_display_2(game, option);
}
