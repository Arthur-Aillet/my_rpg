/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_utils
*/

#include <stdbool.h>

#include "my_button.h"
#include "my_mouse.h"
#include "my_event.h"
#include "my_math.h"

bool is_pressed(button_t bouton, sfRenderWindow *window, int *keys)
{
    sfVector2f mouse_pos = get_global_mouse_pos(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(bouton.sprite);

    if (pos_in_square(mouse_pos, rect) == true && (keys[leftMouse] == 3))
        return (true);
    return (false);
}
