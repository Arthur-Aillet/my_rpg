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
    static sfClock *clock = NULL;
    static particle_t *(*tab[16])(sfRenderWindow *, particle_t *, sfClock *) = {
            snow, rain, fire, dust_circle, dust_up, dust_ur, dust_right,
            dust_dr, fire_up, fire_ur, fire_right, fire_dr, spark,
            elctric_pulse, leaf_fragment, light_dust};

    if (clock == NULL)
        clock = sfClock_create();
    while (start->next != NULL) {
        start = tab[start->type](window, start, clock);
        start = start->next;
        remove_particle(start);
    }
}
