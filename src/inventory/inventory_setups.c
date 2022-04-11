/*
** EPITECH PROJECT, 2022
** rpg - menu setups
** File description:
** setups structures for the menu
*/

#include "inventory_structures.h"
#include <stdlib.h>

static struct object setup_select(void)
{
    struct object result;
    sfSprite *mouse = sfSprite_create();
    sfTexture *tex = sfTexture_createFromFile("sprites/select.png", NULL);

    result.sprite = mouse;
    result.texture = tex;
    sfSprite_setTexture(mouse, tex, 0);
    return (result);
}

static struct object *setup_pages(void)
{
    struct object *result = malloc(sizeof(struct object) * 4);

    sfVector2f scale = {4, 4};
    result[0].sprite = sfSprite_create();
    result[1].sprite = sfSprite_create();
    result[2].sprite = sfSprite_create();
    result[3].sprite = sfSprite_create();
    result[0].texture = sfTexture_createFromFile("assets/img/inventory_background.jpg", NULL);
    result[1].texture = sfTexture_createFromFile("assets/img/inventory.png", NULL);
    result[2].texture = sfTexture_createFromFile("assets/img/ye_olde_map.png", NULL);
    result[3].texture = sfTexture_createFromFile("assets/img/competences.png", NULL);
    for (int i = 0; i < 4; i++) {
        sfSprite_setTexture(result[i].sprite, result[i].texture, 0);
        sfSprite_setScale(result[i].sprite, scale);
    }
    return (result);
}

static struct txtobject setup_text(void)
{
    struct txtobject result;
    result.font = sfFont_createFromFile("assets/font/arcade.TTF");
    result.text = sfText_create();
    return (result);
}

struct backgrounds setup_backgrounds(struct item *items, struct competences *comp, sfRenderWindow *window, char *keys)
{
    struct backgrounds result;

    result.items = items;
    result.pages = setup_pages();
    result.text = setup_text();
    result.window = window;
    result.keys = keys;
    result.comp = comp;
    return (result);
}
