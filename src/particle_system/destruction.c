/*
** EPITECH PROJECT, 2022
** rpg - particle_t destruction
** File description:
** i have become death destroyer of worlds
*/

#include "particles.h"
#include <stdlib.h>

void remove_particle(particle_t *previous)
{
    particle_t *temp = NULL;

    if (previous->next != NULL) {
        temp = previous->next->next;
        sfSprite_destroy(previous->next->object_t->sprite);
        free(previous->next);
    }
    previous->next = temp;
}

void exterminate(particle_t *first)
{
    while(first->next != NULL)
        remove_particle(first);
    sfSprite_destroy(first->object_t->sprite);
    free(first);
}
