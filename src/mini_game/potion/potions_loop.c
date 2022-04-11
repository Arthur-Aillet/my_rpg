/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** potions_loop
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
#include "particles_structures.h"

void potions_loop(window_t *window, int *keys, object *mouse)
{
    object **part = setup_part_sprites();
    font_t **font = font_create_array();
    sound_t **sound = sounds_create_array();
    object *back = create_object("assets/img/potions/background.jpg", VCF{0, 0}, VCF{1, 1});
    object *hammer = create_object("assets/img/potions/hammer.png", VCF{0, 0}, VCF{1, 1});
    object *anvil = create_object("assets/img/potions/anvil.png", VCF{0, 0}, VCF{1.5, 1.5});
    sfFloatRect bounds_anvil = sfSprite_getGlobalBounds(anvil->sprite);
    sfFloatRect bounds_hammer = sfSprite_getGlobalBounds(hammer->sprite);
    struct particle *start = create_particle((sfVector2f) {0, 0}, 0);
    int open = 1;
    int last_has_spawn = 0;

    sfSprite_setOrigin(anvil->sprite, VCF{bounds_anvil.height / 3, bounds_anvil.width / 3});
    sfSprite_setOrigin(hammer->sprite, VCF{bounds_hammer.height / 2, bounds_hammer.width / 2});
    sfSprite_setPosition(anvil->sprite, VCF{1920 / 2 + 5, 1080 / 2 + 100});
    sfSprite_setPosition(hammer->sprite, VCF{1920 / 2 - 70, 1080 / 2 - 65});
    while (sfRenderWindow_isOpen(window->window) && open) {
        set_correct_window_size(window);
        sfRenderWindow_clear(window->window, sfBlack);
        get_events(window->window, keys);
        if (keys[sfKeyEscape] == PRESS)
            open = 0;
        if (CLICKED && sfSprite_getRotation(hammer->sprite) < 41)
            sfSprite_rotate(hammer->sprite, 9);
        if (!CLICKED && sfSprite_getRotation(hammer->sprite) > 0)
            sfSprite_rotate(hammer->sprite, -9);
        sfRenderWindow_drawSprite(window->window, back->sprite, NULL);
        sfRenderWindow_drawSprite(window->window, anvil->sprite, NULL);
        sfRenderWindow_drawSprite(window->window, hammer->sprite, NULL);
        if (sfSprite_getRotation(hammer->sprite) >= 41 && last_has_spawn == 0) {
            for (int i = rand() % 5 + 2; i != 0; i--) {
                start = add_particle(start, (sfVector2f) {1920 / 2, 1080 / 2}, 12, (rand() % 100 + 100) / 10);
            }
            last_has_spawn = 1;
        }
        if (sfSprite_getRotation(hammer->sprite) < 41)
            last_has_spawn = 0;
        update_mouse_cursor(window->window, mouse);
        update_particles(window->window, start, part);
        //sfRenderWindow_drawSprite(window->window, mouse->sprite, NULL);
        sfRenderWindow_display(window->window);
    }
}
