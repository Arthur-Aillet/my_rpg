/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** hammer_loop
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>

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

void destroy_hammer_struct(hammer_t *hammer)
{
    destroy_object(hammer->anvil);
    destroy_object(hammer->background);
    destroy_object(hammer->hammer);
    destroy_object(hammer->for_bar);
    destroy_object(hammer->box_bar);
    free(hammer);
}

hammer_t *setup_hammer_struct(void)
{
    hammer_t *elements = malloc(sizeof(hammer_t));
    sfFloatRect bounds_anvil;
    sfFloatRect bounds_for;
    sfFloatRect bounds_hammer;

    elements->for_bar = create_object
        ("assets/img/potions/forground_progress.png", VCF{1920 / 2, 210}, VCF{2, 2});
    elements->box_bar = create_object
        ("assets/img/potions/box_progress.jpg", VCF{710, 200}, VCF{2, 2});
    elements->background = create_object
        ("assets/img/potions/background.jpg", VCF{0, 0}, VCF{1, 1});
    elements->hammer = create_object
        ("assets/img/potions/hammer.png", VCF{0, 0}, VCF{1, 1});
    elements->anvil = create_object
        ("assets/img/potions/anvil.png", VCF{0, 0}, VCF{1.5, 1.5});
    bounds_anvil = sfSprite_getGlobalBounds(elements->anvil->sprite);
    bounds_hammer = sfSprite_getGlobalBounds(elements->hammer->sprite);
    bounds_for = sfSprite_getGlobalBounds(elements->for_bar->sprite);
    sfSprite_setOrigin(elements->for_bar->sprite,
        VCF{bounds_for.width / 4, bounds_for.height / 4});
    sfSprite_setOrigin(elements->anvil->sprite,
        VCF{bounds_anvil.height / 3, bounds_anvil.width / 3});
    sfSprite_setOrigin(elements->hammer->sprite,
        VCF{bounds_hammer.height / 2, bounds_hammer.width / 2});
    sfSprite_setPosition(elements->anvil->sprite, VCF{965, 640});
    sfSprite_setPosition(elements->hammer->sprite, VCF{890, 475});
    elements->has_spawn = false;
    return (elements);
}

void hammer_controls(hammer_t *elements, struct particle **start, int *keys)
{
    if (CLICKED && sfSprite_getRotation(elements->hammer->sprite) < 41)
        sfSprite_rotate(elements->hammer->sprite, 9);
    if (!CLICKED && sfSprite_getRotation(elements->hammer->sprite) > 0)
        sfSprite_rotate(elements->hammer->sprite, -9);
    if (sfSprite_getRotation(elements->hammer->sprite) >= 41
        && elements->has_spawn == false) {
        for (int i = rand() % 5 + 2; i != 0; i--) {
            *start = add_particle(*start, VCF{1920 / 2, 1080 / 2}, 12,
                (rand() % 100 + 100) / 10);
        }
        elements->has_spawn = true;
        for (int i = 0; elements->points + 1 <= 102 && i < 4; i++)
            elements->points += 1;
    }
    if (sfSprite_getRotation(elements->hammer->sprite) < 41)
        elements->has_spawn = false;
}

void display_hammer(hammer_t *eleme, window_t *window)
{
    sfRenderWindow_drawSprite(window->window, eleme->background->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, eleme->anvil->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, eleme->hammer->sprite, NULL);
    sfSprite_setScale(eleme->for_bar->sprite,
        VCF{(eleme->points > 100) ? 2 : eleme->points / 100 * 2, 2});
    sfRenderWindow_drawSprite(window->window, eleme->box_bar->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, eleme->for_bar->sprite, NULL);
}

void hammer_loop(window_t *window, int *keys, object *mouse, int difficulty)
{
    hammer_t *elements = setup_hammer_struct();
    struct particle *start = create_particle((sfVector2f) {0, 0}, 0, 0);
    int open = true;
    sfClock *clock = sfClock_create();
    elements->points = 0;

    while (sfRenderWindow_isOpen(window->window) && open) {
        set_correct_window_size(window);
        sfRenderWindow_clear(window->window, sfBlack);
        get_events(window->window, keys);
        if (keys[sfKeyEscape] == PRESS || elements->points >= 102)
            open = false;
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= (float) 1 / (difficulty)) {
            elements->points -= (elements->points >= 1) ? 0 : 0;
            elements->points -= (elements->points >= 1) ? 0 : 0;
            sfClock_restart(clock);
        }
        hammer_controls(elements, &start, keys);
        display_hammer(elements, window);
        update_particles(window->window, start);
        update_mouse_cursor(window->window, mouse);
        sfRenderWindow_display(window->window);
    }
    sfClock_destroy(clock);
    destroy_hammer_struct(elements);
}
