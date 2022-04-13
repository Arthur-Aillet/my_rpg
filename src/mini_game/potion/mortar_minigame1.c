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
#include "keyboard.h"
#include "my_csfml_utils.h"
#include "particles.h"

void mortar_loop(game_t *game, potion_t *potion)
{
    minigame_t *elements = setup_hammer_struct();
    particle_t *start = create_particle((sfVector2f) {0, 0}, 0, 0);
    int open = true;
    sfClock *clock = sfClock_create();
    sfSound *sound = sfSound_copy(find_sound("anvil.ogg", game->sounds));

    while (sfRenderWindow_isOpen(game->window->window) && open) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);
        open = hammer_update(game->keys, elements, potion, clock);
        hammer_controls(elements, &start, game->keys, sound);
        display_hammer(elements, game->window, potion);
        update_particles(game->window->window, start);
        update_mouse_cursor(game->window->window, game->mouse);
        sfRenderWindow_display(game->window->window);
    }
    sfClock_destroy(clock);
    destroy_minigame_struct(elements);
}
