/*
** EPITECH PROJECT, 2022
** rpg - snow paricles
** File description:
** *brrrr*
*/

#include "particles.h"
#include "my.h"
#include <math.h>
#include <stdlib.h>

particle_t *snow(sfRenderWindow *window, particle_t *part)
{
    float rdom = fmod(rand(), part->speed * 100) / 100 * 3 / 2;

    if (rand() % 2 == 0)
        rdom *= -1;
    part->age += 1;
    part->pos.x += rdom;
    part->pos.y += part->speed - ABS(rdom);
    part->rotation = rand() % 11 - 5;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_rotate(part->object->sprite, part->rotation);
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return (part);
}
