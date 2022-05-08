/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** water particles
*/

#include "particles.h"
#include <math.h>
#include <stdlib.h>

/*a drop of water falls from the sky
recomended stating pos: {rand() % 1920, 0}
recomended speed: 15*/
particle_t *rain(sfRenderWindow *window, particle_t *part, sfClock *clock)
{
    if (part->speed == 0)
        add_particle(part, VCF {rand() % 1000, rand() % 1000}, 1, 1);
    if (TIME(clock, 0.05)) {
        part->age += 1;
        part->velocity.y = part->speed;
        sfSprite_move(part->object->sprite, part->velocity);
    }
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return part;
}
