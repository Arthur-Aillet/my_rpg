/*
** EPITECH PROJECT, 2022
** rpg - water particles
** File description:
** *gaidojapamxcopacpoa*
*/

#include "particles.h"

particle *rain(sfRenderWindow *window, particle *part)
{
    part->age += 1;
    part->velocity.y = part->speed;
    sfSprite_move(part->object->sprite, part->velocity);
    sfRenderWindow_drawSprite(window, part->object->sprite, NULL);
    return (part);
}
