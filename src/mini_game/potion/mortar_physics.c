/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** mortar_physics
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

void mortar_physics_held(minigame_t *elem, game_t *game, sfVector2f old)
{
    float rotation = sfSprite_getRotation(elem->pilon->sprite);

    sfSprite_setPosition(elem->pilon->sprite,
    get_global_mouse_pos(game->window->window));
    if (old.x > sfSprite_getPosition(game->mouse->sprite).x &&
        (rotation < 90 || rotation > 100))
        sfSprite_rotate(elem->pilon->sprite, ((old.x - sfSprite_getPosition
            (game->mouse->sprite).x) / 10 > 10) ? 10 : (old.x -
            sfSprite_getPosition(game->mouse->sprite).x) / 10);
    if (old.x == sfSprite_getPosition(game->mouse->sprite).x && rotation > 180)
        sfSprite_rotate(elem->pilon->sprite, 5);
    if (old.x == sfSprite_getPosition(game->mouse->sprite).x &&
        sfSprite_getRotation(elem->pilon->sprite) < 180 &&
        sfSprite_getRotation(elem->pilon->sprite) > 0)
        sfSprite_rotate(elem->pilon->sprite, -5);
    if (old.x < sfSprite_getPosition(game->mouse->sprite).x &&
        (rotation < 260 || rotation > 270))
        sfSprite_rotate(elem->pilon->sprite, ((old.x -
            sfSprite_getPosition(game->mouse->sprite).x) / 10 < -10) ? -10 :
            (old.x - sfSprite_getPosition(game->mouse->sprite).x) / 10);
}

void mortar_physics(minigame_t *elements, game_t *game)
{
    sfVector2f old_mouse_pos = get_global_mouse_pos(game->window->window);
    sfFloatRect rect;
    sfFloatRect pilon = sfSprite_getGlobalBounds(elements->pilon->sprite);
    sfFloatRect ground = (sfFloatRect) {0, 1100, 1920, 500};

    if (sfFloatRect_intersects(&ground, &pilon, &rect))
        sfSprite_setPosition(elements->pilon->sprite, VCF{
            get_global_mouse_pos(game->window->window).x,
            (get_global_mouse_pos(game->window->window).y >
            sfSprite_getPosition(elements->pilon->sprite).y) ?
            sfSprite_getPosition(elements->pilon->sprite).y :
            get_global_mouse_pos(game->window->window).y,
            });
    else
        mortar_physics_held(elements, game, old_mouse_pos);
}
