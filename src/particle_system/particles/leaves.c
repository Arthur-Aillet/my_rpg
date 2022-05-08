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
particle_t *leaf_fragment(sfRenderWindow *wnd, particle_t *part, sfClock *clock)
{
    float rdom = fmod(rand(), (part->speed * 2) * 100) / 100 - part->speed;

    part->lifetime = (part->speed == 1) ? 20 : 1920;
    if (part->age <= 0) {
        part->velocity.x = log2f(rdom * rdom);
        part->velocity.y = log2f(part->speed * 4 - ABS(rdom)) * 2;
        part->velocity.y *= -1;
        if (rand() % 2 == 0)
            part->velocity.x *= -1;
    }
    part->age += 1;
    sfSprite_rotate(part->object->sprite, SIGN(part->velocity.x) * 5);
    if (TIME(clock, 0.05)) {
        part->velocity.y *= 0.97;
        part->velocity.y += 0.5;
        part->velocity.x *= 0.97;
        sfSprite_move(part->object->sprite, part->velocity);
    }
    sfRenderWindow_drawSprite(wnd, part->object->sprite, NULL);
    return part;
}

particle_t *light_dust(sfRenderWindow *window, particle_t *part, sfClock *clock)
{
    float random = fmod(rand(), 1000) / 1000000;
    if (part->age == 0) {
        sfSprite_setColor(part->object->sprite, TRANSPARENT(0));
        part->speed /= 3;
        part->velocity = VCF {(fmod(rand(), part->speed * 100) / 100)- part->
            speed / 2, fmod(rand(), part->speed * 100)/ 100 - part->speed / 2};
    }
    if (TIME(clock, 0.05)) {
        sfSprite_setColor(part->object->sprite, TRANSPARENT(part->age / 2));
        sfSprite_scale(part->object->sprite, VCF {1 + random, 1 + random});
        part->age += 1;
        sfSprite_move(part->object->sprite, part->velocity);
    }
    if (part->age > part->lifetime / 1.9 && TIME(clock, 0.05)) {
        sfSprite_setColor(part->object->sprite, FADE);
        sfSprite_scale(part->object->sprite, VCF {1 - random, 1 - random});
    }
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return part;
}
