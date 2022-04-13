/*
** EPITECH PROJECT, 2022
** rpg - fire particles
** File description:
** *fire noises*
*/

#include "particles.h"
#include "my.h"
#include <math.h>
#include <stdlib.h>

particle_t *fire_dr(sfRenderWindow *window, particle_t *part)
{
    float f = (part->speed * 2) + SIGN(part->speed);
    float rdom = fmod(rand(), f) - ABS(part->speed);

    part->age += 1;
    part->pos.x += part->speed / 2 + rdom;
    part->pos.y += part->speed / 2;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object_t->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object_t->sprite, NULL);
    return(part);
}

particle_t *fire_right(sfRenderWindow *window, particle_t *part)
{
    float f = (part->speed * 2) + SIGN(part->speed);

    part->age += 1;
    part->pos.x += part->speed;
    part->pos.y += fmod(rand(), f) - ABS(part->speed);
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object_t->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object_t->sprite, NULL);
    return(part);
}

particle_t *fire_ur(sfRenderWindow *window, particle_t *part)
{
    float f = (part->speed * 2) + SIGN(part->speed);
    float rdom = fmod(rand(), f) - ABS(part->speed);

    part->age += 1;
    part->pos.x += part->speed / 2 + rdom;
    part->pos.y -= part->speed / 2;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object_t->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object_t->sprite, NULL);
    return(part);
}

particle_t *fire_up(sfRenderWindow *window, particle_t *part)
{
    float f = (part->speed * 2) + SIGN(part->speed);

    part->age += 1;
    part->pos.x += fmod(rand(), f) - ABS(part->speed);
    part->pos.y -= part->speed;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object_t->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object_t->sprite, NULL);
    return (part);
}

particle_t *fire(sfRenderWindow *window, particle_t *part)
{
    part->age += 1;
    part->pos.x += fmod(rand(), (part->speed + 1)) - part->speed / 2;
    part->pos.y += fmod(rand(), (part->speed)) - part->speed / 1.9;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object_t->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object_t->sprite, NULL);
    return (part);
}
