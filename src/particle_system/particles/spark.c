/*
** EPITECH PROJECT, 2022
** rpg - spark paricles
** File description:
** ah *shakes hand*
*/

#include "particles.h"
#include "my.h"
#include <math.h>
#include <stdlib.h>

particle_t *spark(sfRenderWindow *window, particle_t *part)
{
    float rdom = fmod(rand(), (part->speed * 2) * 100) / 100 - part->speed;
    float decay = (float) (rand() % 7 - 3) / 100;

    if (part->age <= 0) {
        part->velocity.x = log2f(rdom * rdom);
        part->velocity.y = log2f(part->speed - ABS(rdom)) * 2;
        part->velocity.y *= -1;
        if (rand() % 2 == 0)
            part->velocity.x *= -1;
    }
    part->velocity.x *= 0.98 + decay;
    part->velocity.y *= 0.98 + decay;
    part->velocity.y += 0.05;
    part->age += 1;
    sfSprite_rotate(part->object_t->sprite, SIGN(part->velocity.x) * 5);
    sfSprite_setColor(part->object_t->sprite, TRANSPARENT(255 - part->age));
    sfSprite_scale(part->object_t->sprite, VCF {0.99 + decay, 0.99 + decay});
    sfSprite_move(part->object_t->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object_t->sprite, NULL);
    return(part);
}
