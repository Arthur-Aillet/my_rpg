/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** lists
*/

#include "my_button.h"
#include "my_csfml_utils.h"
#include "my_game_struct.h"

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>

list_t *create_list(sfVector2f pos, game_t *game, char *text)
{
    list_t *list = malloc(sizeof(list_t));

    list->value = false;
    list->down = button_create(VCF{1.7, 1.7}, pos, true);
    button_setup_sounds(list->down, SOUNDG("hover.ogg"),
        SOUNDG("click.ogg"), 100);
    list->up = button_create(VCF{1.7, 1.7}, pos, true);
    button_setup_sounds(list->up, SOUNDG("hover.ogg"),
        SOUNDG("click.ogg"), 100);
    button_setup_texture_file(list->down,
        (sfIntRect){0, 0, 250, 40}, "assets/img/menu/list_up.jpg");
    button_setup_texture_file(list->up,
        (sfIntRect){0, 0, 250, 40}, "assets/img/menu/list_down.jpg");
    button_setup_text(list->down, text, FONTG("Ancient.ttf"), 40);
    button_setup_text(list->up, text, FONTG("Ancient.ttf"), 40);
    return (list);
}

void update_list(list_t *list, game_t *game)
{
    if (is_pressed(list->down, game->window->window, game->keys)
        && list->value == true)
        list->value = false;
    else if (is_pressed(list->up, game->window->window, game->keys)
        && list->value == false)
        list->value = true;
    if (list->value == true) {
        update_button(game->window->window, list->up, game->keys);
        for (int i = 0; list->element[i] != NULL; i++) {
            update_button(game->window->window, list->element[i], game->keys);
        }
    } else
        update_button(game->window->window, list->down, game->keys);
}

void destroy_list(list_t *list)
{
    destroy_button(list->down);
    destroy_button(list->up);
    for (int i = 0; list->element[i] != NULL; i++)
        destroy_button(list->element[i]);
    free(list->element);
    free(list);
}
