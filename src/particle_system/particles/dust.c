/*
** EPITECH PROJECT, 2022
** rpg - dust particles
** File description:
** *cough* *cough*
*/

#include "particles.h"
#include "my.h"
#include <math.h>
#include <stdlib.h>

/*a particle with one purpose, going down and right.
you can make them go up and left with negative speed
recomended starting pos: right on the source
recomended speed: 10*/
particle_t *dust_dr(sfRenderWindow *window, particle_t *part)
{
    float f = (part->speed * 2) + SIGN(part->speed);
    float rdom = fmod(rand(), f) - ABS(part->speed);

    part->age += 1;
    part->pos.x += part->speed / 2 + rdom;
    part->pos.y += part->speed / 2;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_setColor(part->object->sprite, FADE);
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

/*a particle with one purpose, going right.
you can make them go left with negative speed
recomended starting pos: right on the source
recomended speed: 10*/
particle_t *dust_right(sfRenderWindow *window, particle_t *part)
{
    float f = (part->speed * 2) + SIGN(part->speed);

    part->age += 1;
    part->pos.x += part->speed;
    part->pos.y += fmod(rand(), f) - ABS(part->speed);
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_setColor(part->object->sprite, FADE);
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

/*a particle with one purpose, going up and right.
you can make them go down and left with negative speed
recomended starting pos: right on the source
recomended speed: 10*/
particle_t *dust_ur(sfRenderWindow *window, particle_t *part)
{
    float f = (part->speed * 2) + SIGN(part->speed);
    float rdom = fmod(rand(), f) - ABS(part->speed);

    part->age += 1;
    part->pos.x += part->speed / 2 + rdom;
    part->pos.y -= part->speed / 2;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_setColor(part->object->sprite, FADE);
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

/*a particle with one purpose, going up.
you can make them go down with negative speed
recomended starting pos: right on the source
recomended speed: 10*/
particle_t *dust_up(sfRenderWindow *window, particle_t *part)
{
    float f = (part->speed * 2) + SIGN(part->speed);
    part->age += 1;
    part->pos.x += fmod(rand(), f) - ABS(part->speed);
    part->pos.y -= part->speed;
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_setColor(part->object->sprite, FADE);
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

/*a particle that will go in a random direction,
but in a group of about a thousand it makes a circle simmilar to
the conequences of dropping anything in your grandparent's attic
recomended starting pos: point of inpact
recomended speed: 15*/
particle_t *dust_circle(sfRenderWindow *window, particle_t *part)
{
    float rdom = fmod(rand(), (part->speed * 2 + 1) * 100) / 100 - part->speed;

    if (part->age <= 4) {
        part->velocity.x = log2f(rdom * rdom);
        part->velocity.y = log2f(part->speed - ABS(rdom)) * 2;
        if (rand() % 2 == 0)
            part->velocity.y *= -1;
        if (rand() % 2 == 0)
            part->velocity.x *= -1;
    }
    part->velocity.x *= 0.97;
    part->velocity.y *= 0.97;
    part->age += 1;
    sfSprite_setColor(part->object->sprite, FADE);
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}
