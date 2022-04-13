/*
** EPITECH PROJECT, 2022
** rpg - particle destruction
** File description:
** i have become death destroyer of worlds
*/

#include "particles.h"
#include <stdlib.h>

void remove_particle(particle *previous)
{
    particle *temp = NULL;

    if (previous->next != NULL) {
        temp = previous->next->next;
        sfSprite_destroy(previous->next->object->sprite);
        free(previous->next);
    }
    previous->next = temp;
}

void exterminate(particle *first)
{
    while(first->next != NULL)
        remove_particle(first);
    sfSprite_destroy(first->object->sprite);
    free(first);
}
