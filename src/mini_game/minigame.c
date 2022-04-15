/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** minigame
*/

#include <stdlib.h>

#include "potions.h"
#include "my_csfml_utils.h"
#include "keyboard.h"

int minigame_update(char *keys, minigame_t *elements, potion_t *pot, sfClock *clock)
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

void display_minigame(minigame_t *eleme, window_t *window, potion_t *pot)
{
    sfRenderWindow_drawSprite(window->window, eleme->background->sprite, NULL);
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

minigame_t *create_generic_elements(void)
{
    minigame_t *elements = malloc(sizeof(minigame_t));

    elements->circle_full = create_object
        ("assets/img/potions/circle_full.png", VCF{960, 200}, VCF{2, 2});
    elements->circle_empty = create_object
        ("assets/img/potions/circle_empty.png", VCF{960, 200}, VCF{2, 2});
    elements->for_bar = create_object
        ("assets/img/potions/forground_progress.png", VCF{960, 270}, VCF{2, 2});
    elements->box_bar = create_object
        ("assets/img/potions/box_progress.jpg", VCF{710, 260}, VCF{2, 2});
    elements->background = create_object
        ("assets/img/potions/background.jpg", VCF{0, 0}, VCF{1, 1});
    return (elements);
}

minigame_t *setup_elements(void)
{
    minigame_t *elements = create_generic_elements();
    sfFloatRect bd_for = sfSprite_getGlobalBounds(elements->for_bar->sprite);
    sfFloatRect bd_fl = sfSprite_getGlobalBounds(elements->circle_full->sprite);
    sfFloatRect bd_e = sfSprite_getGlobalBounds(elements->circle_empty->sprite);

    elements->has_spawn = false;
    elements->step = 1;
    sfSprite_setOrigin(elements->circle_full->sprite,
        VCF{bd_fl.width / 4, bd_fl.height / 4});
    sfSprite_setOrigin(elements->circle_empty->sprite,
        VCF{bd_e.width / 4, bd_e.height / 4});
    sfSprite_setOrigin(elements->for_bar->sprite,
        VCF{bd_for.width / 4, bd_for.height / 4});
    elements->points = 0;
    return (elements);
}

void destroy_minigame_struct(minigame_t *structure)
{
    destroy_object(structure->anvil);
    destroy_object(structure->background);
    destroy_object(structure->hammer);
    destroy_object(structure->for_bar);
    destroy_object(structure->box_bar);
    destroy_object(structure->circle_full);
    destroy_object(structure->circle_empty);
    free(structure);
}
