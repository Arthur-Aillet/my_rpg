/*
** EPITECH PROJECT, 2022
** rpg - water particles
** File description:
** *gaidojapamxcopacpoa*
*/

#include "particles.h"

particle_t*rain(sfRenderWindow *window, particle_t*part)
{
    part->age += 1;
    part->velocity.y = part->speed;
    sfSprite_move(part->object_t->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object_t->sprite, NULL);
    return (part);
}
