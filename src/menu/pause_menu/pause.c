/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** pause
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

static pause_t *setup_pause(game_t *game)
{
    pause_t *pause = malloc(sizeof(pause_t));

    pause->retour = button_create(VCF{2.2, 1}, VCF{game->game->pos_cam.x - 350, game->game->pos_cam.y - 175}, true);
    button_setup_texture_file(pause->retour,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(pause->retour, "Retrun", FONTG("Ancient.ttf"), 40);
    button_setup_offset(pause->retour, VCF{-.09, .2}, VCF{.17, .06}, VCF{0, 0});
        button_setup_sounds(pause->retour,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    pause->option = button_create(VCF{2.2, 1}, VCF{game->game->pos_cam.x - 350, game->game->pos_cam.y}, true);
    button_setup_texture_file(pause->option,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(pause->option, "Option", FONTG("Ancient.ttf"), 40);
    button_setup_offset(pause->option, VCF{-.09, .2}, VCF{.17, .06}, VCF{0, 0});
        button_setup_sounds(pause->option,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    pause->quit = button_create(VCF{2.2, 1}, VCF{game->game->pos_cam.x - 350, game->game->pos_cam.y + 175}, true);
    button_setup_texture_file(pause->quit,
        (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(pause->quit, "Quit", FONTG("Ancient.ttf"), 40);
    button_setup_offset(pause->quit, VCF{-.09, .2}, VCF{.17, .06}, VCF{0, 0});
        button_setup_sounds(pause->quit,
        SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 100);
    pause->back = create_object("assets/img/menu/pause_menu.jpg", VCF{game->game->pos_cam.x - 1920 / 2, game->game->pos_cam.y - 1080 / 2}, VCF{1.5, 1.5});
    return (pause);
}

static void destroy_pause(pause_t *pause)
{
    destroy_object(pause->back);
    destroy_button(pause->quit);
    destroy_button(pause->option);
    destroy_button(pause->retour);
    free(pause);
}

int pause_menu(game_t *game)
{
    pause_t *pause = setup_pause(game);
    int open = 1;
    int returned = 0;
    const sfView *stored = sfView_copy(sfRenderWindow_getView(game->window->window));
    const sfView *view = sfRenderWindow_getView(game->window->window);

    while (sfRenderWindow_isOpen(game->window->window) && open) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);
        if (is_pressed(pause->retour, game->window->window, game->keys))
            open = 0;
        if (is_pressed(pause->quit, game->window->window, game->keys)) {
            open = 0;
            returned = 1;
        }
        if (is_pressed(pause->option, game->window->window, game->keys)) {
            sfView_setCenter(view, VCF{1920 / 2, 1080 / 2});
            sfRenderWindow_setView(game->window->window, view);
            option(game);
            sfRenderWindow_setView(game->window->window, stored);
            game->ESC = 0;
        }
        if (game->ESC == PRESS)
            open = 0;
        sfRenderWindow_drawSprite(game->window->window,
            pause->back->sprite, NULL);
        update_button(game->window->window, pause->quit, game->keys);
        update_button(game->window->window, pause->option, game->keys);
        update_button(game->window->window, pause->retour, game->keys);
        update_mouse_cursor(game->window->window, game->mouse);
        sfRenderWindow_display(game->window->window);
    }
    sfRenderWindow_setView(game->window->window, stored);
    sfView_destroy(stored);
    destroy_pause(pause);
    return returned;
}
