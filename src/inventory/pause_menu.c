/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** pause_menu
*/

#include "csfml_libs.h"
#include "mouse.h"
#include "keyboard.h"
#include "inventory.h"
#include "my_csfml_utils.h"

#include <stdlib.h>

int get_pause_event(sfRenderWindow *window, char *keys)
{
    sfEvent event;
    int close = 0;
    keys = get_keyboard_input(event, keys, window);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (ESC == PRESS)
        close = 1;
    return(close);
}

sfVector2f utofv2(sfVector2u vector)
{
    sfVector2f result;

    result.x = vector.x;
    result.y = vector.y;
    return (result);
}

void pause_menu(sfRenderWindow *window, char *keys)
{
    sfSprite *pause_sprite = sfSprite_create();
    sfSprite *bg_sprite = sfSprite_create();
    sfTexture *pause = sfTexture_createFromFile("asset/img/pause_menu.png", NULL);
    sfTexture *bg = sfTexture_createFromFile("asset/img/ye_olde_map.png", NULL);
    sfSprite_setTexture(bg_sprite, bg, 0);
    sfSprite_setTexture(pause_sprite, pause, 0);
    sfVector2f p2scale = {5, 5};
    sfVector2f p2pos = {90, 0};
    object *mouse = create_object("assets/img/cursor.h", p2pos, (sfVector2f) {0, 0});
    sfSprite_setScale(bg_sprite, p2scale);
    sfSprite_setPosition(bg_sprite, p2pos);
    sfVector2u size_of_window;
    int close = 0;
    while (close == 0) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg_sprite, NULL);
        sfRenderWindow_drawSprite(window, pause_sprite, NULL);
        size_of_window = sfRenderWindow_getSize(window);
        close = get_pause_event(window, keys);
        draw_mouse(window, mouse->sprite);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(pause_sprite);
    sfTexture_destroy(pause);
    sfSprite_destroy(bg_sprite);
    sfTexture_destroy(bg);
}
