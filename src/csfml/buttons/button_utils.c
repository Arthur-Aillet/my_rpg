/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_utils
*/

#include <stdbool.h>

#include "my_button.h"
#include "my_mouse.h"
#include "keyboard.h"
#include "my_math.h"

bool is_pressed(button_t bouton, sfRenderWindow *window, char *keys)
{
    sfVector2f mouse_pos = get_global_mouse_pos(window);
    sfFloatRect rect = sfSprite_getGlobalBounds(bouton.sprite);

    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y) == true
        && (LCLICK == RELEASE))
        return (true);
    return (false);
}

void display_button(sfRenderWindow *window, button_t *but)
{
    sfRenderWindow_drawSprite(window, but->sprite, NULL);
    if (but->display_text == true)
        sfRenderWindow_drawText(window, but->text.text, NULL);
}
