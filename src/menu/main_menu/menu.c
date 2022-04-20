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
#include "menu.h"
#include "my_rpg.h"
#include "my_mouse.h"
#include "my_button.h"
#include "keyboard.h"
#include "my_csfml_utils.h"
#include "potions.h"
#include "inventory_structures.h"

void setup_menu_buttons(main_menu_t *menu, game_t *game)
{
    button_setup_text(menu->new_game, "New game", FONTG("Ancient.ttf"), 40);
    button_setup_text(menu->options, "Options", FONTG("Ancient.ttf"), 40);
    button_setup_text(menu->quit, "Quit", FONTG("Ancient.ttf"), 40);
    button_setup_text(menu->continue_game,
        "Continue game", FONTG("Ancient.ttf"), 40);
    button_setup_sounds(menu->new_game,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_sounds(menu->continue_game,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_sounds(menu->options,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_sounds(menu->quit,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_offset(menu->new_game, VCF{-.09, .2}, VCF{.17, .06});
    button_setup_offset(menu->continue_game, VCF{-.09, .2}, VCF{.17, .06});
    button_setup_offset(menu->options, VCF{-.09, .2}, VCF{.17, .06});
    button_setup_offset(menu->quit, VCF{-.09, .2}, VCF{.17, .06});
}

main_menu_t *init_main_menu(game_t *game)
{
    main_menu_t *menu = malloc(sizeof(main_menu_t));

    menu->back = create_object("assets/img/menu/focus.jpg", VCF{0, -30}, VCF{1, 1});
    menu->title = create_object("assets/img/menu/title.png", VCF{480, -50}, VCF{.25, .25});
    menu->new_game = button_create(VCF{2.2, 1}, VCF{960, 412}, true);
    menu->continue_game = button_create(VCF{2.2, 1}, VCF{960, 540}, true);
    menu->options = button_create(VCF{2.2, 1}, VCF{960, 668}, true);
    menu->quit = button_create(VCF{2.2, 1}, VCF{960, 796}, true);
    button_setup_texture(menu->new_game,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_texture(menu->continue_game,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_texture(menu->options,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_texture(menu->quit,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    setup_menu_buttons(menu, game);
    return (menu);
}

void update_menu(main_menu_t *menu, game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, menu->back->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window, menu->title->sprite, NULL);
    update_button(game->window->window, menu->new_game, game->keys);
    update_button(game->window->window, menu->continue_game, game->keys);
    update_button(game->window->window, menu->options, game->keys);
    update_button(game->window->window, menu->quit, game->keys);
    update_mouse_cursor(game->window->window, game->mouse);
    sfRenderWindow_display(game->window->window);
}

int menu(game_t *game, item_t *items, competences_t *comp)
{
    main_menu_t *menu = init_main_menu(game);
    potion_t *potion;
    int open = 1;

    while (sfRenderWindow_isOpen(game->window->window) && open) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);
        if (is_pressed(menu->quit, game->window->window, game->keys))
            open = 0;
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
        if (is_pressed(menu->new_game, game->window->window, game->keys))
            game_loop(game);
        update_menu(menu, game);
    }
    return 0;
}
