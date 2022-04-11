/*
** EPITECH PROJECT, 2022
** my_rpg_temp
** File description:
** mouse
*/

#include "csfml_libs.h"
#include "inventory.h"
#include "my_csfml_utils.h"

struct object setup_mouse(void)
{
    struct object result;
    sfSprite *mouse = sfSprite_create();
    sfTexture *tex = sfTexture_createFromFile("assets/img/cursors.png", NULL);

    result.sprite = mouse;
    result.texture = tex;
    sfSprite_setTexture(mouse, tex, 0);
    return (result);
}

void draw_mouse(sfRenderWindow *window, sfSprite *mouse)
{
    sfVector2f mousepos;

    mousepos = itofv2(sfMouse_getPositionRenderWindow(window));
    sfSprite_setPosition(mouse, mousepos);
    sfRenderWindow_drawSprite(window, mouse, NULL);
}
