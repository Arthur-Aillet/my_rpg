/*
** EPITECH PROJECT, 2022
** rpg - enegy particles
** File description:
** oh what's that do? *enters the backrooms*
*/

#include "particles.h"
#include "my.h"
#include <math.h>
#include <stdlib.h>

particle_t *magic_vibe(sfRenderWindow *window, particle_t *part, sfClock *clock)
{
    float f = (part->speed * 2) + SIGN(part->speed);

    if (TIME(clock, 0.1)) {
        if (part->rotation <= 10)
            part->scale.x = 1;
        if (part->rotation >= 190)
            part->scale.x = -1;
        part->rotation += (rand() % 5) * part->scale.x;
        sfSprite_setColor(part->object->sprite, sfColor_fromRGBA
            (200 - part->rotation, part->rotation, 200, 100));
        part->age += 1;
        part->pos.x -= part->speed;
        part->pos.y += fmod(rand(), f) - ABS(part->speed);
    }
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return part;
}
