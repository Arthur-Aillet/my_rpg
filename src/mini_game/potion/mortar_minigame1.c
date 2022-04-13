/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** mortar_minigame1
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "my_sound.h"
#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "my_rpg.h"
#include "potions.h"
#include "my_mouse.h"
#include "my_button.h"
#include "particles.h"
#include "my_event.h"
#include "my_csfml_utils.h"
#include "particles_structures.h"

void mortar_loop(window_t *window, int *keys, sound_t **sounds, object *mouse, potion_t *potion)
{
    minigame_t *elements = setup_hammer_struct();
    struct particle *start = create_particle((sfVector2f) {0, 0}, 0, 0);
    int open = true;
    sfClock *clock = sfClock_create();
    sfSound *sound = sfSound_copy(find_sound("anvil.ogg", sounds));

    while (sfRenderWindow_isOpen(window->window) && open) {
        set_correct_window_size(window);
        sfRenderWindow_clear(window->window, sfBlack);
        get_events(window->window, keys);
        open = hammer_update(keys, elements, potion, clock);
        hammer_controls(elements, &start, keys, sound);
        display_hammer(elements, window, potion);
        update_particles(window->window, start);
        update_mouse_cursor(window->window, mouse);
        sfRenderWindow_display(window->window);
    }
    sfClock_destroy(clock);
    destroy_minigame_struct(elements);
}
