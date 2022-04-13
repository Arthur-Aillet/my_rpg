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

/*a single spark that will dwindle before siapearing
recomended starting pos: exact point of inpact
recomended speed: 10*/
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
    sfSprite_rotate(part->object->sprite, SIGN(part->velocity.x) * 5);
    sfSprite_setColor(part->object->sprite, TRANSPARENT(255 - part->age));
    sfSprite_scale(part->object->sprite, VCF {0.99 + decay, 0.99 + decay});
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return(part);
}
