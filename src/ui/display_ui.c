/*
** EPITECH PROJECT, 2022
** rpg - display ui
** File description:
** displays the ui
*/

#include "csfml_libs.h"
#include "my_csfml_utils.h"
#include "ui.h"
#include <stdlib.h>

static object_t **get_parts(void)
{
    static object_t **result = NULL;
    sfVector2f pos_circle = {0, 0};
    sfVector2f pos_health = {130, 50};
    sfVector2f scale = {0.5, 0.5};

    if (result != NULL)
        return (result);
    result = malloc(sizeof(object_t) * 5);
    result[0] = create_object("assets/img/ui/pp_bg.png", pos_circle, scale);
    result[1] = create_object("assets/img/ui/pp_circle.png", pos_circle, scale);
    result[2] = create_object("assets/img/ui/health_bg.png", pos_health, scale);
    result[3] = create_object("assets/img/ui/health.png", pos_health, scale);
    result[4] = create_object("assets/img/bap_open.png", VCF {30, 30}, scale);
    return (result);
}

static void sf_sprite_set_pixel_size(sfSprite *sprite, sfVector2f size)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);
    sfVector2f scale = {size.x / rect.width, size.y / rect.height};

    sfSprite_setScale(sprite, scale);
}

static void display_circle(sfRenderWindow *window, object_t **parts)
{
    sf_sprite_set_pixel_size(parts[4]->sprite, VCF {100, 100});
    sfRenderWindow_drawSprite(window, parts[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, parts[4]->sprite, NULL);
    sfRenderWindow_drawSprite(window, parts[1]->sprite, NULL);
}

void display_ui(sfRenderWindow *window, ui_t ui)
{
    object_t **parts = get_parts();
    display_health(window, ui.health, ui.max_health, parts);
    display_circle(window, parts);
}