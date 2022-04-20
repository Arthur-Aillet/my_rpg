/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>

#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "my_rpg.h"
#include "my_mouse.h"
#include "my_button.h"
#include "keyboard.h"
#include "my_csfml_utils.h"
#include "potions.h"
#include "inventory_structures.h"

int menu(game_t *game, item_t *items, competences_t *comp)
{
    object_t *test = create_object("assets/img/menu/menu_back.jpg", VCF{0, 0}, VCF{1, 1});
    button_t *new_game = button_create(VCF{2.2, 1}, VCF{1920 / 2, 300}, true);
    button_t *continue_game = button_create(VCF{2.2, 1}, VCF{1920 / 2, 300 + 79 * 1.618}, true);
    button_t *options = button_create(VCF{2.2, 1}, VCF{1920 / 2, 300 + 79 * 1.618 * 2}, true);
    button_t *quit = button_create(VCF{2.2, 1}, VCF{1920 / 2, 300 + 79 * 1.618 * 3}, true);
    potion_t *potion;

    button_setup_texture(new_game, (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(new_game, "New game", find_font("Ancient.ttf", game->fonts), 40);
    button_setup_sounds(new_game, find_sound("hover.ogg", game->sounds), find_sound("click.ogg", game->sounds), 100);
    button_setup_offset(new_game, VCF{-.09, .2}, VCF{.17, .06});
    button_setup_texture(continue_game, (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(continue_game, "Continue game", find_font("Ancient.ttf", game->fonts), 40);
    button_setup_sounds(continue_game, find_sound("hover.ogg", game->sounds), find_sound("click.ogg", game->sounds), 100);
    button_setup_offset(continue_game, VCF{-.09, .2}, VCF{.17, .06});
    button_setup_texture(options, (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(options, "Options", find_font("Ancient.ttf", game->fonts), 40);
    button_setup_sounds(options, find_sound("hover.ogg", game->sounds), find_sound("click.ogg", game->sounds), 100);
    button_setup_offset(options, VCF{-.09, .2}, VCF{.17, .06});
    button_setup_texture(quit, (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(quit, "Quit", find_font("Ancient.ttf", game->fonts), 40);
    button_setup_sounds(quit, find_sound("hover.ogg", game->sounds), find_sound("click.ogg", game->sounds), 100);
    button_setup_offset(quit, VCF{-.09, .2}, VCF{.17, .06});
    while (sfRenderWindow_isOpen(game->window->window)) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);
        if (game->keys[sfKeyEscape] == PRESS)
            inventory(game->window->window, items, comp, game->keys);
        if (game->keys[sfKeyP] == PRESS) {
            potion = malloc(sizeof(potion_t));
            potion->current_step = 1;
            potion->numbers_steps = 2;
            potion->difficulty = 2;
            hammer_loop(game->window, game->keys, game->mouse, potion);
            free(potion);
        }
        if (game->keys[sfKeyG] == PRESS)
            game_loop(game);
        sfRenderWindow_drawSprite(game->window->window, test->sprite, NULL);
        update_button(game->window->window, new_game, game->keys);
        update_button(game->window->window, continue_game, game->keys);
        update_button(game->window->window, options, game->keys);
        update_button(game->window->window, quit, game->keys);
        update_mouse_cursor(game->window->window, game->mouse);
        sfRenderWindow_display(game->window->window);
    }
    return 0;
}
