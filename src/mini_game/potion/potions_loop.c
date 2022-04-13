/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** potion_loop
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "my_rpg.h"
#include "my_mouse.h"
#include "my_button.h"
#include "my_event.h"
#include "my_csfml_utils.h"
#include "potions.h"
#include "inventory_structures.h"

void potion_loop(window_t *window, font_t **font, sound_t **sound, int *keys)
{
    object *test = create_object("test", VCF{0, 0}, VCF{60, 33});
    object *mouse = create_object("test", VCF{0, 0}, VCF{1, 1});
    button_t *fire_potion = button_create(VCF{2, 1}, VCF{1920 / 2, 1080 / 2}, true);
    potion_t *potion = malloc(sizeof(potion_t));
    int open = 1;

    button_setup_texture(fire_potion, (sfIntRect){0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(fire_potion, "Fire potion", find_font("Ancient.ttf", font), 40);
    button_setup_sounds(fire_potion, find_sound("hover.ogg", sound), find_sound("click.ogg", sound), 10);
    button_setup_offset(fire_potion, VCF{1.1, 1.1}, VCF{1.2, 1.2});
    while (sfRenderWindow_isOpen(window->window) && open) {
        set_correct_window_size(window);
        sfRenderWindow_clear(window->window, sfBlack);
        get_events(window->window, keys);
        if (keys[sfKeyEscape] == PRESS)
            open = 0;
        if (is_pressed(*fire_potion, window->window, keys)) {
            potion->current_step = 0;
            potion->numbers_steps = 2;
            potion->difficulty = 2;
            while (potion->current_step != potion->numbers_steps) {
                hammer_loop(window, keys, sound, mouse, potion);
                if (keys[sfKeyEscape] == PRESS)
                    break;
                potion->current_step += 1;
            }
        }
        sfRenderWindow_drawSprite(window->window, test->sprite, NULL);
        update_button(window->window, fire_potion, keys);
        update_mouse_cursor(window->window, mouse);
        sfRenderWindow_display(window->window);
    }
    free(potion);
}
