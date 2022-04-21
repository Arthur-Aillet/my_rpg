/*
** EPITECH PROJECT, 2022
** rpg - water particles
** File description:
** *gaidojapamxcopacpoa*
*/

#include "particles.h"

/*a drop of water falls from the sky
recomended stating pos: {rand() % 1920, 0}
recomended speed: 15*/
particle_t*rain(sfRenderWindow *window, particle_t *part, sfClock *clock)
{
    if (TIME(clock, 0.05)) {
        part->age += 1;
        part->velocity.y = part->speed;
        sfSprite_move(part->object->sprite, part->velocity);
    }
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return (part);
}
