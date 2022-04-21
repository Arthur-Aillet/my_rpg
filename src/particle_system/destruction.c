/*
** EPITECH PROJECT, 2022
** rpg - particle_t destruction
** File description:
** i have become death destroyer of worlds
*/

#include "particles.h"
#include <stdlib.h>

/*removes the next particle in the list*/
void remove_particle(particle_t *prev)
{
    particle_t *temp = NULL;

    if (prev->next == NULL || prev->next->age < prev->next->lifetime)
        return;
    temp = prev->next->next;
    sfSprite_destroy(prev->next->object->sprite);
    free(prev->next);
    prev->next = temp;
}

/*destroys all the particles int the list*/
void exterminate(particle_t *first)
{
    while(first->next != NULL) {
        remove_particle(first);
        first = first->next;
    }
    sfSprite_destroy(first->object->sprite);
    free(first);
}
