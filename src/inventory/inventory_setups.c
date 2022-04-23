/*
** EPITECH PROJECT, 2022
** rpg - menu setups
** File description:
** setups structures for the menu
*/

#include "inventory_structures.h"
#include "my_csfml_utils.h"
#include "my_game_struct.h"
#include <stdlib.h>

static object_t **setup_pages(void)
{
    object_t **result = malloc(sizeof(object_t *) * 4);
    sfVector2f scale = {4, 4};
    sfVector2f pos = {0, 0};

    result[0] = create_object("assets/img/inventory_background.jpg", pos, scale);
    result[1] = create_object("assets/img/inventory.png", pos, scale);
    result[2] = create_object("assets/img/ye_olde_map.png", pos, scale);
    result[3] = create_object("assets/img/competences.png", pos, scale);
    return (result);
}

static txtobject_t setup_text(font_t **fonts)
{
    txtobject_t result;
    result.font = fonts[1]->font;
    result.text = sfText_create();
    return (result);
}

backgrounds_t setup_backgrounds(game_t *game)
{
    backgrounds_t result;

    result.items = game->items;
    result.pages = setup_pages();
    result.text = setup_text(game->fonts);
    result.window = game->window->window;
    result.keys = game->keys;
    result.comp = game->comp;
    return (result);
}
