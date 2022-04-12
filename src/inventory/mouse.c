/*
** EPITECH PROJECT, 2022
** my_rpg_temp
** File description:
** mouse
*/

#include "csfml_libs.h"
#include "inventory.h"
#include "my_csfml_utils.h"

void draw_mouse(sfRenderWindow *window, sfSprite *mouse)
{
    sfVector2f mousepos;

    mousepos = itofv2(sfMouse_getPositionRenderWindow(window));
    sfSprite_setPosition(mouse, mousepos);
    sfRenderWindow_drawSprite(window, mouse, NULL);
}
