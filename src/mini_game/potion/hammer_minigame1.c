/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** hammer_minigame1
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

void hammer_controls(minigame_t *elements, struct particle **start, int *keys, sfSound *sound)
{
    if (CLICKED && sfSprite_getRotation(elements->hammer->sprite) < 41)
        sfSprite_rotate(elements->hammer->sprite, 9);
    if (!CLICKED && sfSprite_getRotation(elements->hammer->sprite) > 0)
        sfSprite_rotate(elements->hammer->sprite, -9);
    if (sfSprite_getRotation(elements->hammer->sprite) >= 41
        && elements->has_spawn == false) {
        sfSound_play(sound);
        for (int i = rand() % 5 + 2; i != 0; i--) {
            *start = add_particle(*start, VCF{960, 1080 / 2}, 12,
                (rand() % 100 + 100) / 10);
        }
        elements->has_spawn = true;
        for (int i = 0; elements->points + 1 <= 102 && i < 4; i++)
            elements->points += 1;
    }
    if (sfSprite_getRotation(elements->hammer->sprite) < 41)
        elements->has_spawn = false;
}

void display_hammer(minigame_t *eleme, window_t *window, potion_t *pot)
{
    sfRenderWindow_drawSprite(window->window, eleme->background->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, eleme->anvil->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, eleme->hammer->sprite, NULL);
    sfSprite_setScale(eleme->for_bar->sprite,
        VCF{(eleme->points > 100) ? 2 : eleme->points / 100 * 2, 2});
    sfRenderWindow_drawSprite(window->window, eleme->box_bar->sprite, NULL);
    for (int i = pot->numbers_steps; i > 0; i--) {
        if (i > pot->numbers_steps - pot->current_step) {
            sfSprite_setPosition(eleme->circle_full->sprite, VCF{960 - ((108) *
                i) + ((108) * ((float) (pot->numbers_steps + 1) / 2)), 200});
            sfRenderWindow_drawSprite(window->window,
                eleme->circle_full->sprite, NULL);
        } else {
            sfSprite_setPosition(eleme->circle_empty->sprite, VCF{960 - ((108) *
                i) + ((108) * ((float) (pot->numbers_steps + 1) / 2)), 200});
            sfRenderWindow_drawSprite(window->window,
                eleme->circle_empty->sprite, NULL);
        }
    }
    sfRenderWindow_drawSprite(window->window, eleme->for_bar->sprite, NULL);
}

int hammer_update(int *keys, minigame_t *elements, potion_t *pot, sfClock *clock)
{
    if (keys[sfKeyEscape] == PRESS || elements->points >= 102)
        return (0);
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >=
        (float) 1 / (pot->difficulty)) {
        elements->points -= (elements->points >= 1) ? 1 : 0;
        elements->points -= (elements->points >= 1) ? 1 : 0;
        sfClock_restart(clock);
    }
    return (1);
}

void hammer_loop(window_t *window, int *keys, sound_t **sounds, object *mouse, potion_t *potion)
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
