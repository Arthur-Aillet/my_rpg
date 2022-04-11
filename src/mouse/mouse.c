/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** mouse_manager
*/

#include "my_csfml_utils.h"

#include <SFML/Graphics.h>

#include <math.h>

sfVector2f get_global_mouse_pos(sfRenderWindow *window)
{
    return (sfRenderWindow_mapPixelToCoords(window,
    sfMouse_getPositionRenderWindow(window), sfRenderWindow_getView(window)));
}

void update_mouse_cursor(sfRenderWindow *window, object *mouse)
{
    sfVector2f mouse_pos = get_global_mouse_pos(window);

    sfSprite_setPosition(mouse->sprite, mouse_pos);
    sfRenderWindow_drawSprite(window, mouse->sprite, NULL);
}
