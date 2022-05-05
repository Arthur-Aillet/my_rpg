/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** how to play
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

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
#include "math.h"
#include "inventory_structures.h"

static how_to_t *setup_how_to(game_t *game)
{
    how_to_t *how = malloc(sizeof(how_to_t));

    how->quit = button_create(VCF{1, 1}, VCF{1760, 990}, true);
    button_setup_texture_file(how->quit,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_sounds(how->quit,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    button_setup_text(how->quit, "Retrun", FONTG("Ancient.ttf"), 40);
    button_setup_offset(how->quit, VCF{.05, .05}, VCF{.1, .1}, VCF{0, 0});
    how->back = create_object("assets/img/menu/how_to_play.jpg",
        VCF{0, 0}, VCF{1, 1});
    return (how);
}

static void destroy_how_to(how_to_t *how)
{
    destroy_object(how->back);
    destroy_button(how->quit);
    free(how);
}

int how_to_play(game_t *game)
{
    how_to_t *how = setup_how_to(game);
    int open = 1;

    while (sfRenderWindow_isOpen(game->window->window) && open) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);
        if (is_pressed(how->quit, game->window->window, game->keys))
            open = 0;
        if (game->ESC == PRESS)
            open = 0;
        sfRenderWindow_drawSprite(game->window->window,
            how->back->sprite, NULL);
        update_button(game->window->window, how->quit, game->keys);
        update_mouse_cursor(game->window->window, game->mouse);
        sfRenderWindow_display(game->window->window);
    }
    destroy_how_to(how);
    return 0;
}
