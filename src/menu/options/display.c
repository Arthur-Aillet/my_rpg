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

static void check_all_buttons(list_t *list, game_t *game)
{
    for (int i = 0; list->element[i] != NULL; i++) {
        update_button(game->window->window, list->element[i], game->keys);
        if (is_pressed(list->element[i], game->window->window, game->keys)) {
            sfRenderWindow_setFramerateLimit(game->window->window,
                my_getnbr(sfText_getString(list->element[i]->text.text)));
            game->window->framerate = my_getnbr(
                sfText_getString(list->element[i]->text.text));
        }
    }
}

void update_list_frame(list_t *list, game_t *game)
{
    if (is_pressed(list->down, game->window->window, game->keys)
        && list->value == true)
        list->value = false;
    else if (is_pressed(list->up, game->window->window, game->keys)
        && list->value == false)
        list->value = true;
    if (list->value == true) {
        update_button(game->window->window, list->up, game->keys);
        check_all_buttons(list, game);
    } else
        update_button(game->window->window, list->down, game->keys);
}

static void update_display_2(game_t *game, options_menu_t *op)
{
    update_button(game->window->window, op->screen_type_right, game->keys);
    update_button(game->window->window, op->screen_type_left, game->keys);
    update_button(game->window->window, op->screen_type_apply, game->keys);
    update_checkbox_vsync(op->vsync, game);
    update_list(op->resolution, game);
    if (op->resolution->value == true && is_pressed(op->resolution->element[0],
        game->window->window, game->keys))
        sfRenderWindow_setSize(game->window->window, VCU{1920, 1920 * 9/16});
    if (op->resolution->value == true && is_pressed(op->resolution->element[1],
        game->window->window, game->keys))
        sfRenderWindow_setSize(game->window->window, VCU{1680, 1680 * 9/16});
    if (op->resolution->value == true && is_pressed(op->resolution->element[2],
        game->window->window, game->keys))
        sfRenderWindow_setSize(game->window->window, VCU{1440, 1440 * 9/16});
    if (op->resolution->value == true && is_pressed(op->resolution->element[3],
        game->window->window, game->keys))
        sfRenderWindow_setSize(game->window->window, VCU{1072, 1072 * 9/16});
    if (op->resolution->value == false)
        update_list_frame(op->frame, game);
}

void update_display(game_t *game, options_menu_t *op)
{
    sfRenderWindow_drawText(game->window->window, op->vsync_title, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        op->screen_type_background->sprite, NULL);
    sfRenderWindow_drawText(game->window->window, op->screen_type_text, NULL);
    sfRenderWindow_drawText(game->window->window, op->screen_type_title, NULL);
    if (is_pressed(op->screen_type_left, game->window->window, game->keys)) {
        op->screen_type_state = MAX(op->screen_type_state - 1, 0);
        change_window(op);
    }
    if (is_pressed(op->screen_type_right, game->window->window, game->keys)) {
        op->screen_type_state = MIN(op->screen_type_state + 1, 2);
        change_window(op);
    }
    if (is_pressed(op->screen_type_apply, game->window->window, game->keys)) {
        game->window->type = op->screen_type_state;
        sfRenderWindow_destroy(game->window->window);
        create_windows(game->window);
    }
    update_display_2(game, op);
}
