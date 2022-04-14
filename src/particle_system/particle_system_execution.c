/*
** EPITECH PROJECT, 2022
** rpg - particle system execution
** File description:
** executes the particles int the chained list
*/

#include "csfml_libs.h"
#include "particles.h"
#include <stdlib.h>

/*this function goes trough the chained list of particles and moves, rotates,
fades, scales, kills and displays all of them*/
void update_particles(sfRenderWindow *window, particle_t *start)
{
    static particle_t *(*tab[15])(sfRenderWindow *, particle_t *) = {
            snow, rain, fire, dust_circle, dust_up, dust_ur, dust_right,
            dust_dr, fire_up, fire_ur, fire_right, fire_dr, spark,
            elctric_pulse, leaf_fragment};

    while (start->next != NULL) {
        start = tab[start->type](window, start);
        start = start->next;
        if (start->next != NULL && start->next->age > start->next->lifetime)
            remove_particle(start);
    }
}
