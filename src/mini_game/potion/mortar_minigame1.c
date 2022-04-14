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

void mortar_physics(minigame_t *elements, game_t *game)
{
    sfVector2f old_mouse_pos = get_global_mouse_pos(game->window->window);
    sfFloatRect rect;
    sfFloatRect pilon = sfSprite_getGlobalBounds(elements->pilon->sprite);
    sfFloatRect ground = (sfFloatRect){0, 1100, 1920, 500};

    if (sfFloatRect_intersects(&ground, &pilon, &rect))
        sfSprite_setPosition(elements->pilon->sprite, VCF{
            get_global_mouse_pos(game->window->window).x,
            (get_global_mouse_pos(game->window->window).y >
            sfSprite_getPosition(elements->pilon->sprite).y) ?
            sfSprite_getPosition(elements->pilon->sprite).y :
            get_global_mouse_pos(game->window->window).y,
            });
    else {
        sfSprite_setPosition(elements->pilon->sprite,
        get_global_mouse_pos(game->window->window));
        if (old_mouse_pos.x > sfSprite_getPosition(game->mouse->sprite).x &&
            (sfSprite_getRotation(elements->pilon->sprite) < 90
            || sfSprite_getRotation(elements->pilon->sprite) > 100))
            sfSprite_rotate(elements->pilon->sprite, ((old_mouse_pos.x -
                sfSprite_getPosition(game->mouse->sprite).x) / 10 > 10) ? 10 :
                (old_mouse_pos.x -
                sfSprite_getPosition(game->mouse->sprite).x) / 10);
        if (old_mouse_pos.x == sfSprite_getPosition(game->mouse->sprite).x &&
            sfSprite_getRotation(elements->pilon->sprite) > 180)
            sfSprite_rotate(elements->pilon->sprite, 5);
        if (old_mouse_pos.x == sfSprite_getPosition(game->mouse->sprite).x &&
            sfSprite_getRotation(elements->pilon->sprite) < 180 &&
            sfSprite_getRotation(elements->pilon->sprite) > 0)
            sfSprite_rotate(elements->pilon->sprite, -5);
        if (old_mouse_pos.x < sfSprite_getPosition(game->mouse->sprite).x &&
            (sfSprite_getRotation(elements->pilon->sprite) < 260
            || sfSprite_getRotation(elements->pilon->sprite) > 270))
            sfSprite_rotate(elements->pilon->sprite, ((old_mouse_pos.x -
                sfSprite_getPosition(game->mouse->sprite).x) / 10 < -10) ? -10 :
                (old_mouse_pos.x -
                sfSprite_getPosition(game->mouse->sprite).x) / 10);
    }
}

void mortar_crush_plants(minigame_t *elements, bool *grab, particle_t **start)
{
    sfFloatRect rect;
    sfFloatRect rect2;
    int nbr_of_leaves = rand() % 3 + 1;
    sfFloatRect pilon = sfSprite_getGlobalBounds(elements->pilon->sprite);

    rect.top = 1080 / 2 + 70;
    rect.left = 1920 / 2 - 1;
    rect.width = 1;
    rect.height = 10;
    if (!sfFloatRect_intersects(&rect, &pilon, &rect2)
        && pilon.top < rect.top - 20)
        elements->has_spawn = false;
    if (*grab == false || pilon.top > rect.top - 200)
        elements->has_spawn = true;
    if (elements->has_spawn == false && *grab == true
    && sfFloatRect_intersects(&rect, &pilon, &rect2)) {
        sfSound_play(elements->sound);
        for (int i = 0; i != nbr_of_leaves; i++)
            *start = add_particle(*start, VCF{1920 / 2 + rand()
                % 120 - 60, 1080 / 2 + 35 + rand() % 10}, LEAF,
                (rand() % 100 + 100) / 10);
        elements->points += 8;
        elements->step = elements->step + 1;
        if (elements->step == 4)
            elements->step = 1;
        if (elements->step == 1)
            sfSprite_setTexture(elements->leaves->sprite, elements->leaves1, sfFalse);
        if (elements->step == 2)
            sfSprite_setTexture(elements->leaves->sprite, elements->leaves2, sfFalse);
        if (elements->step == 3)
            sfSprite_setTexture(elements->leaves->sprite, elements->leaves3, sfFalse);
        elements->has_spawn = true;
    }
}

void mortar_controls(minigame_t *elements, game_t *game, bool *grab, particle_t **start)
{
    sfFloatRect rect;
    sfFloatRect pilon = sfSprite_getGlobalBounds(elements->pilon->sprite);
    sfFloatRect ground = (sfFloatRect){0, 1100, 1920, 500};

    rect.top = sfSprite_getPosition(elements->pilon->sprite).y - 20;
    rect.left = sfSprite_getPosition(elements->pilon->sprite).x - 20;
    rect.width = 40;
    rect.height = 150;
    if (game->LCLICK && sfFloatRect_contains(&rect,
        get_global_mouse_pos(game->window->window).x,
        get_global_mouse_pos(game->window->window).y))
        *grab = true;
    if (*grab == false && game->LCLICK && !sfFloatRect_contains(&rect,
        get_global_mouse_pos(game->window->window).x,
        get_global_mouse_pos(game->window->window).y))
        if (!sfFloatRect_intersects(&ground, &pilon, &rect))
            sfSprite_move(elements->pilon->sprite, VCF{0, 15});
    if (!game->LCLICK) {
        if (!sfFloatRect_intersects(&ground, &pilon, &rect))
            sfSprite_move(elements->pilon->sprite, VCF{0, 15});
        *grab = false;
    }
    if (*grab == true)
        mortar_physics(elements, game);
    mortar_crush_plants(elements, grab, start);
}

void display_mortar(minigame_t *elem, window_t *window, potion_t *pot)
{
    display_minigame(elem, window, pot);
    sfRenderWindow_drawSprite(window->window, elem->mortar_back->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, elem->leaves->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, elem->mortar_front->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, elem->pilon->sprite, NULL);
}

minigame_t *setup_mortar_struct(sound_t **sounds)
{
    minigame_t *elements = setup_elements();
    sfFloatRect bd_mortar_front;
    sfFloatRect bd_mortar_back;
    sfFloatRect bd_pilon;
    sfFloatRect bd_leaves;

    elements->sound = sfSound_copy(find_sound("leaves.ogg", sounds));
    elements->has_spawn = true;
    elements->leaves1 = sfTexture_createFromFile("assets/img/potions/leaves.png", NULL);
    elements->leaves2 = sfTexture_createFromFile("assets/img/potions/leaves2.png", NULL);
    elements->leaves3 = sfTexture_createFromFile("assets/img/potions/leaves3.png", NULL);
    elements->pilon = create_object
        ("assets/img/potions/pilon.png", VCF{0, 0}, VCF{1, 1});
    elements->mortar_back = create_object
        ("assets/img/potions/mortar_back.png", VCF{0, 0}, VCF{2, 2});
    elements->mortar_front = create_object
        ("assets/img/potions/mortar_front.png", VCF{0, 0}, VCF{2, 2});
    elements->leaves = create_textured_object
        (elements->leaves1, VCF{0, 0}, VCF{2, 2});
    bd_pilon = sfSprite_getGlobalBounds(elements->pilon->sprite);
    bd_mortar_back = sfSprite_getGlobalBounds(elements->mortar_back->sprite);
    bd_mortar_front = sfSprite_getGlobalBounds(elements->mortar_front->sprite);
    bd_leaves = sfSprite_getGlobalBounds(elements->leaves->sprite);
    sfSprite_setOrigin(elements->pilon->sprite,
        VCF{bd_pilon.width / 2, bd_pilon.height / 2 - 75});
    sfSprite_setOrigin(elements->mortar_back->sprite,
        VCF{bd_mortar_back.width / 4, bd_mortar_back.height / 4});
    sfSprite_setOrigin(elements->mortar_front->sprite,
        VCF{bd_mortar_front.width / 4, bd_mortar_front.height / 4});
    sfSprite_setOrigin(elements->leaves->sprite,
        VCF{bd_leaves.width / 4, bd_leaves.height / 4});
    sfSprite_setPosition(elements->pilon->sprite, VCF{1920 / 2, 700});
    sfSprite_setPosition(elements->mortar_back->sprite, VCF{1920 / 2, 1080 / 2});
    sfSprite_setPosition(elements->mortar_front->sprite, VCF{1920 / 2, 1080 / 2});
    sfSprite_setPosition(elements->leaves->sprite, VCF{1920 / 2, 1080 / 2});
    return (elements);
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
