/*
** EPITECH PROJECT, 2022
** rpg - particles structures
** File description:
** here be explenations
*/

#include <csfml_libs.h>
#include "my_csfml_utils.h"

#ifndef PARTICLES_STRUCTURES_H_
    #define PARTICLES_STRUCTURES_H_

    #define SIGN(x) ((x > 0) ? (1) : (-1))
    #define SFSGP(x) sfSprite_getPosition(x)
    #define SMOOTHY (part->pos.y - SFSGP(part->object_t->sprite).y) / 10
    #define SMOOTHX (part->pos.x - SFSGP(part->object_t->sprite).x) / 10
    #define TRANSPARENT(x) sfColor_fromRGBA(255, 255, 255, x)

typedef struct particle_s {
    sfVector2f pos;
    sfVector2f trajectory;
    sfVector2f velocity;
    sfVector2f scale;
    object_t *object_t;
    int age;
    int lifetime;
    int type;
    float speed;
    float rotation;
    particle_t *next;
} particle_t;

particle_t *spark(sfRenderWindow *window, particle_t *part);

particle_t *rain(sfRenderWindow *window, particle_t *part);

particle_t *snow(sfRenderWindow *window, particle_t *part);

particle_t *fire(sfRenderWindow *window, particle_t *part);
particle_t *fire_up(sfRenderWindow *window, particle_t *part);
particle_t *fire_ur(sfRenderWindow *window, particle_t *part);
particle_t *fire_right(sfRenderWindow *window, particle_t *part);
particle_t *fire_dr(sfRenderWindow *window, particle_t *part);

particle_t *dust_circle(sfRenderWindow *window, particle_t *part);
particle_t *dust_up(sfRenderWindow *window, particle_t *part);
particle_t *dust_ur(sfRenderWindow *window, particle_t *part);
particle_t *dust_right(sfRenderWindow *window, particle_t *part);
particle_t *dust_dr(sfRenderWindow *window, particle_t *part);

void update_particles(sfRenderWindow *window,
particle_t *start);
particle_t *create_particle(sfVector2f pos, int type, int speed);
particle_t *add_particle(particle_t *first, sfVector2f pos, int, int);
void exterminate(particle_t *first);
void remove_particle(particle_t *previous);

#endif /* !PARTICLES_STRUCTURES_H_ */
