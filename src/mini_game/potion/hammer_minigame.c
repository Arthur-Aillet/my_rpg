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
#include "keyboard.h"
#include "my_csfml_utils.h"
#include "particles.h"

minigame_t *setup_hammer_struct(void)
{
    minigame_t *elements = setup_elements();
    sfFloatRect bd_anvil;
    sfFloatRect bd_hammer;

    elements->hammer = create_object
        ("assets/img/potions/hammer.png", VCF{0, 0}, VCF{1, 1});
    elements->anvil = create_object
        ("assets/img/potions/anvil.png", VCF{0, 0}, VCF{1.5, 1.5});
    bd_anvil = sfSprite_getGlobalBounds(elements->anvil->sprite);
    bd_hammer = sfSprite_getGlobalBounds(elements->hammer->sprite);
    sfSprite_setOrigin(elements->anvil->sprite,
        VCF{bd_anvil.height / 3, bd_anvil.width / 3});
    sfSprite_setOrigin(elements->hammer->sprite,
        VCF{bd_hammer.height / 2, bd_hammer.width / 2});
    sfSprite_setPosition(elements->anvil->sprite, VCF{965, 640});
    sfSprite_setPosition(elements->hammer->sprite, VCF{890, 475});
    return (elements);
}

void hammer_controls(minigame_t *elem, particle_t **st, char *keys, sfSound *sn)
{
    if (LCLICK == 1 && sfSprite_getRotation(elem->hammer->sprite) < 41)
        sfSprite_rotate(elem->hammer->sprite, 9);
    if (LCLICK != 1 && sfSprite_getRotation(elem->hammer->sprite) > 0)
        sfSprite_rotate(elem->hammer->sprite, -9);
    if (sfSprite_getRotation(elem->hammer->sprite) >= 41
        && elem->has_spawn == false) {
        sfSound_play(sn);
        for (int i = rand() % 5 + 2; i != 0; i--) {
            *st = add_particle(*st, VCF{960, 1080 / 2}, 12,
                (rand() % 100 + 100) / 10);
        }
        elem->has_spawn = true;
        for (int i = 0; elem->points + 1 <= 102 && i < 8; i++)
            elem->points += 1;
    }
    if (sfSprite_getRotation(elem->hammer->sprite) < 41)
        elem->has_spawn = false;
}

void display_hammer(minigame_t *eleme, window_t *window, potion_t *pot)
{
    display_minigame(eleme, window, pot);
    sfRenderWindow_drawSprite(window->window, eleme->anvil->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, eleme->hammer->sprite, NULL);
}

void hammer_loop(game_t *game, potion_t *potion)
{
    minigame_t *elements = setup_hammer_struct();
    particle_t *start = create_particle((sfVector2f) {0, 0}, 0, 0);
    int open = true;
    sfClock *clock = sfClock_create();
    sfSound *sound = find_sound("anvil.ogg", game->sounds);

    while (sfRenderWindow_isOpen(game->window->window) && open) {
        set_correct_window_size(game->window);
        sfRenderWindow_clear(game->window->window, sfBlack);
        game->keys = get_keyboard_input(game->keys, game->window->window);
        open = minigame_update(game->keys, elements, potion, clock);
        hammer_controls(elements, &start, game->keys, sound);
        display_hammer(elements, game->window, potion);
        update_particles(game->window->window, start);
        update_mouse_cursor(game->window->window, game->mouse);
        sfRenderWindow_display(game->window->window);
    }
    sfClock_destroy(clock);
    destroy_minigame_struct(elements);
}
