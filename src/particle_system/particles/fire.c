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

particle *fire_dr(sfRenderWindow *window, particle *part)
{
    float f = (part->speed * 2) + SIGN(part->speed);
    float rdom = fmod(rand(), f) - ABS(part->speed);

    part->age += 1;
    part->pos.x += part->speed / 2 + rdom;
    part->pos.y += part->speed / 2;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

particle *fire_right(sfRenderWindow *window, particle *part)
{
    float f = (part->speed * 2) + SIGN(part->speed);

    part->age += 1;
    part->pos.x += part->speed;
    part->pos.y += fmod(rand(), f) - ABS(part->speed);
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

particle *fire_ur(sfRenderWindow *window, particle *part)
{
    float f = (part->speed * 2) + SIGN(part->speed);
    float rdom = fmod(rand(), f) - ABS(part->speed);

    part->age += 1;
    part->pos.x += part->speed / 2 + rdom;
    part->pos.y -= part->speed / 2;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

particle *fire_up(sfRenderWindow *window, particle *part)
{
    float f = (part->speed * 2) + SIGN(part->speed);

    part->age += 1;
    part->pos.x += fmod(rand(), f) - ABS(part->speed);
    part->pos.y -= part->speed;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return (part);
}

particle *fire(sfRenderWindow *window, particle *part)
{
    part->age += 1;
    part->pos.x += fmod(rand(), (part->speed + 1)) - part->speed / 2;
    part->pos.y += fmod(rand(), (part->speed)) - part->speed / 1.9;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return (part);
}
