/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** potions_loop
*/

#include <SFML/Graphics.h>

#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "my_rpg.h"
#include "my_mouse.h"
#include "my_button.h"
#include "my_event.h"
#include "my_csfml_utils.h"
#include "inventory_structures.h"

void potions_loop(window_t *window, int *keys, object *mouse)
{
    font_t **font = font_create_array();
    sound_t **sound = sounds_create_array();
    object *back = create_object("assets/img/potions/background.jpg", VCF{0, 0}, VCF{1, 1});
    int open = 1;

    while (sfRenderWindow_isOpen(window->window) && open) {
        set_correct_window_size(window);
        sfRenderWindow_clear(window->window, sfBlack);
        get_events(window->window, keys);
        if (keys[sfKeyEscape] == PRESS)
            open = 0;
        sfRenderWindow_drawSprite(window->window, back->sprite, NULL);
        update_mouse_cursor(window->window, mouse);
        //sfRenderWindow_drawSprite(window->window, mouse->sprite, NULL);
        sfRenderWindow_display(window->window);
    }
}
