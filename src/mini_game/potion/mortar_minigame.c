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

void evolve_elements(minigame_t *elem)
{
    elem->points += 8;
    elem->step = elem->step + 1;
    if (elem->step == 4)
        elem->step = 1;
    if (elem->step == 1)
        sfSprite_setTexture(elem->leaves->sprite, elem->leaves1, sfFalse);
    if (elem->step == 2)
        sfSprite_setTexture(elem->leaves->sprite, elem->leaves2, sfFalse);
    if (elem->step == 3)
        sfSprite_setTexture(elem->leaves->sprite, elem->leaves3, sfFalse);
    elem->has_spawn = true;
}

void mortar_crush_plants(minigame_t *elem, bool *grab, particle_t **start)
{
    sfFloatRect rect = (sfFloatRect) {959, 610, 1, 10};
    sfFloatRect rect2;
    int nbr_of_leaves = rand() % 3 + 1;
    sfFloatRect pilon = sfSprite_getGlobalBounds(elem->pilon->sprite);

    if (!sfFloatRect_intersects(&rect, &pilon, &rect2)
        && pilon.top < rect.top - 20)
        elem->has_spawn = false;
    if (*grab == false || pilon.top > rect.top - 200)
        elem->has_spawn = true;
    if (elem->has_spawn == false && *grab == true
    && sfFloatRect_intersects(&rect, &pilon, &rect2)) {
        sfSound_play(elem->sound);
        for (int i = 0; i != nbr_of_leaves; i++)
            *start = add_particle(*start, VCF{1920 / 2 + rand()
                % 120 - 60, 1080 / 2 + 35 + rand() % 10}, LEAF,
                (rand() % 500 + 100) / 10);
        evolve_elements(elem);
    }
}

void mortar_controls(minigame_t *elm, game_t *game, bool *grab, particle_t **start)
{
    sfVector2f mouse_pos = get_global_mouse_pos(game->window->window);
    sfFloatRect rect = (sfFloatRect) {sfSprite_getPosition(elm->pilon->sprite).x
        - 20, sfSprite_getPosition(elm->pilon->sprite).y - 20, 40, 150};
    sfFloatRect pilon = sfSprite_getGlobalBounds(elm->pilon->sprite);
    sfFloatRect ground = (sfFloatRect){0, 1100, 1920, 500};

    if (game->LCLICK && sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y))
        *grab = true;
    if (*grab == false && game->LCLICK
        && !sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y))
        if (!sfFloatRect_intersects(&ground, &pilon, &rect))
            sfSprite_move(elm->pilon->sprite, VCF{0, 15});
    if (!game->LCLICK) {
        if (!sfFloatRect_intersects(&ground, &pilon, &rect))
            sfSprite_move(elm->pilon->sprite, VCF{0, 15});
        *grab = false;
    }
    if (*grab == true)
        mortar_physics(elm, game);
    mortar_crush_plants(elm, grab, start);
}

void display_mortar(minigame_t *elem, window_t *window, potion_t *pot)
{
    display_minigame(elem, window, pot);
    sfRenderWindow_drawSprite(window->window, elem->mortar_back->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, elem->leaves->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, elem->mortar_front->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, elem->pilon->sprite, NULL);
}

void mortar_loop(game_t *game, potion_t *potion)
{
    minigame_t *elements = setup_mortar_struct(game->sounds);
    particle_t *start = create_particle((sfVector2f) {0, 0}, 0, 0);
    int open = true;
    bool grab = false;
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(game->window->window) && open) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);
        mortar_controls(elements, game, &grab, &start);
        open = minigame_update(game->keys, elements, potion, clock);
        display_mortar(elements, game->window, potion);
        update_particles(game->window->window, start);
        update_mouse_cursor(game->window->window, game->mouse);
        sfRenderWindow_display(game->window->window);
    }
    sfClock_destroy(clock);
}
