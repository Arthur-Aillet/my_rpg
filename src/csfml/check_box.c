/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** check_box
*/

#include "my_button.h"
#include "my_csfml_utils.h"
#include "my_game_struct.h"

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>

check_t *create_check(sfVector2f pos, game_t *game)
{
    check_t *check = malloc(sizeof(check_t));

    check->status = false;
    check->on = button_create(VCF{1.5, 1.5}, pos, false);
    button_setup_sounds(check->on, SOUNDG("hover.ogg"),
        SOUNDG("click.ogg"), 100);
    check->off = button_create(VCF{1.5, 1.5}, pos, false);
    button_setup_sounds(check->off, SOUNDG("hover.ogg"),
        SOUNDG("click.ogg"), 100);
    button_setup_texture_file(check->on,
        (sfIntRect){0, 0, 35, 35}, "assets/img/menu/check_on.jpg");
    button_setup_texture_file(check->off,
        (sfIntRect){0, 0, 35, 35}, "assets/img/menu/check_off.jpg");
    button_setup_offset(check->on, VCF{.1, .1}, VCF{.2, .2}, VCF{0, 0});
    button_setup_offset(check->off, VCF{.1, .1}, VCF{.2, .2}, VCF{0, 0});
    return (check);
}

void update_checkbox(check_t *check, game_t *game)
{
    if (is_pressed(check->off, game->window->window, game->keys)
        && check->status == false)
        check->status = true;
    else if (is_pressed(check->on, game->window->window, game->keys)
        && check->status == true)
        check->status = false;
    update_button_no_display(game->window->window, check->on, game->keys);
    update_button_no_display(game->window->window, check->off, game->keys);
    if (check->status == 0)
        display_button(game->window->window, check->off);
    else
        display_button(game->window->window, check->on);
}

void update_checkbox_vsync(check_t *check, game_t *game)
{
    if (is_pressed(check->off, game->window->window, game->keys)
        && check->status == false) {
        check->status = true;
        sfRenderWindow_setVerticalSyncEnabled(game->window->window, true);
        game->window->vsync = true;
    }
    else if (is_pressed(check->on, game->window->window, game->keys)
        && check->status == true) {
        check->status = false;
        sfRenderWindow_setVerticalSyncEnabled(game->window->window, false);
        game->window->vsync = false;
    }
    update_button_no_display(game->window->window, check->on, game->keys);
    update_button_no_display(game->window->window, check->off, game->keys);
    if (check->status == 0)
        display_button(game->window->window, check->off);
    else
        display_button(game->window->window, check->on);
}

void destroy_check_box(check_t *check)
{
    destroy_button(check->off);
    destroy_button(check->on);
    free(check);
}
