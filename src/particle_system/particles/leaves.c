/*
** EPITECH PROJECT, 2022
** rog - leaves particles
** File description:
** aight imma leave
*/

#include "particles.h"
#include "my.h"
#include <math.h>
#include <stdlib.h>

/*a fragment of a once proud and mighty tree destined to fall in the underworld
recomended starting pos: exact point of inpact
recomended speed: 50*/
particle_t *leaf_fragment(sfRenderWindow *window, particle_t *part)
{
    float rdom = fmod(rand(), (part->speed * 2) * 100) / 100 - part->speed;

    if (part->age <= 0) {
        part->velocity.x = log2f(rdom * rdom);
        part->velocity.y = log2f(part->speed * 4 - ABS(rdom)) * 2;
        part->velocity.y *= -1;
        if (rand() % 2 == 0)
            part->velocity.x *= -1;
    }
    part->velocity.x *= 0.97;
    part->velocity.y *= 0.97;
    part->velocity.y += 0.5;
    part->age = sfSprite_getPosition(part->object->sprite).y;
    sfSprite_rotate(part->object->sprite, SIGN(part->velocity.x) * 5);
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}
