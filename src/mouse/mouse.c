/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** mouse_manager
*/

#include <math.h>

#include "my_csfml_utils.h"

object setup_mouse(char *filename, sfVector2f scale)
{
    object mouse;
    sfIntRect rect = (sfIntRect){0, 0, 24, 24};

    mouse.sprite = sfSprite_create();
    mouse.texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTextureRect(mouse.sprite, rect);
    sfSprite_setScale(mouse.sprite, scale);
    sfSprite_setTexture(mouse.sprite, mouse.texture, sfFalse);
    return (mouse);
}

sfVector2f get_global_mouse_pos(sfRenderWindow *window)
{
    sfVector2f mouse_pos = itofv2(sfMouse_getPositionRenderWindow(window));
    sfVector2u screen_size = sfRenderWindow_getSize(window);

    mouse_pos.x = mouse_pos.x / screen_size.x * 1920;
    mouse_pos.y = mouse_pos.y / screen_size.y * 1080;
    return (mouse_pos);
 }

void update_mouse_cursor(sfRenderWindow *window, object mouse, sfClock *clock)
{
    sfVector2f mouse_pos = get_global_mouse_pos(window);
    sfIntRect rect;
    sfIntRect rect_current = sfSprite_getTextureRect(mouse.sprite);
    float sec = fmod(sfTime_asSeconds(sfClock_getElapsedTime(clock)), 1);

    if ((sec > 0.98 && sec < 1) || (sec > 0.48 && sec < 0.5)) {
        if (rect_current.left < 466 - 24)
            rect = (sfIntRect){rect_current.left + 24, 0, 24, 24};
        else
            rect = (sfIntRect){0, 0, 24, 24};
        sfSprite_setTextureRect(mouse.sprite, rect);
    }
    sfSprite_setPosition(mouse.sprite, mouse_pos);
    sfRenderWindow_drawSprite(window, mouse.sprite, NULL);
}
