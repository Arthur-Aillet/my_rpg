/*
** EPITECH PROJECT, 2022
** rpg - fire particles
** File description:
** *fire noises*
*/

#include "particles.h"
#include "my.h"
#include "json.h"
#include <math.h>
#include <stdlib.h>

/*a particle with one purpose, going down and right.
you can make them go up and left with negative speed
recomended starting pos: right on the source
recomended speed: 10*/
particle_t *fire_dr(sfRenderWindow *window, particle_t *part, sfClock *clock)
{
    float f = (part->speed * 2) + SIGN(part->speed);
    float rdom = fmod(rand(), f) - ABS(part->speed);

    if (TIME(clock, 0.05)) {
        part->age += 1;
        part->pos.x += part->speed / 2 + rdom;
        part->pos.y += part->speed / 2;
    }
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

/*a particle with one purpose, going right.
you can make them go left with negative speed
recomended starting pos: right on the source
recomended speed: 10*/
particle_t *fire_right(sfRenderWindow *window, particle_t *part, sfClock *clock)
{
    float f = (part->speed * 2) + SIGN(part->speed);

    if (TIME(clock, 0.05)) {
        part->age += 1;
        part->pos.x += part->speed;
        part->pos.y += fmod(rand(), f) - ABS(part->speed);
    }
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

/*a particle with one purpose, going up and right.
you can make them go down and left with negative speed
recomended starting pos: right on the source
recomended speed: 10*/
particle_t *fire_ur(sfRenderWindow *window, particle_t *part, sfClock *clock)
{
    float f = (part->speed * 2) + SIGN(part->speed);
    float rdom = fmod(rand(), f) - ABS(part->speed);

    if (TIME(clock, 0.05)) {
        part->age += 1;
        part->pos.x += part->speed / 2 + rdom;
        part->pos.y -= part->speed / 2;
    }
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}

/*a particle with one purpose, going up.
you can make them go down with negative speed
recomended starting pos: right on the source
recomended speed: 10*/
particle_t *fire_up(sfRenderWindow *window, particle_t *part, sfClock *clock)
{
    float f = (part->speed * 2) + SIGN(part->speed);

    if (TIME(clock, 0.05)) {
        part->age += 1;
        part->pos.x += fmod(rand(), f) - ABS(part->speed);
        part->pos.y -= part->speed;
    }
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return (part);
}

/*bits of divergent flames floating arround going aproximately up
recommended starting pos: the base of the fire
recomended speed: 20*/
particle_t *fire(sfRenderWindow *window, particle_t *part, sfClock *clock)
{
    if (TIME(clock, 0.05)) {
        part->age += 1;
        part->pos.x += fmod(rand(), (part->speed + 1)) - part->speed / 2;
        part->pos.y += fmod(rand(), (part->speed)) - part->speed / 1.9;
        sfSprite_scale(part->object->sprite, VCF {0.98, 0.98});
        sfSprite_setColor(part->object->sprite, FADE);
    }
    part->velocity.x = SMOOTHX;
    part->velocity.y = SMOOTHY;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return (part);
}
