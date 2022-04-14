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

    #define MAX(x, y) (x > y) ? (x) : (y)
    #define SIGN(x) ((x > 0) ? (1) : (-1))
    #define SFSGP(x) sfSprite_getPosition(x)
    #define SMOOTHY (part->pos.y - SFSGP(part->object->sprite).y) / 10
    #define SMOOTHX (part->pos.x - SFSGP(part->object->sprite).x) / 10
    #define TRANSPARENT(x) sfColor_fromRGBA(255, 255, 255, x)
    #define FADE TRANSPARENT(MAX(255 - (part->age * 255 / part->lifetime), 0))

    #define SNOW            0
    #define RAIN            1
    #define FIRE            2
    #define DUST_CIRCLE     3
    #define DUST_UP         4
    #define DUST_UP_RIGHT   5
    #define DUST_RIGHT      6
    #define DUST_DOWN_RIGHT 7
    #define FIRE_UP         8
    #define FIRE_UP_RIGHT   9
    #define FIRE_RIGHT      10
    #define FIRE_DOWN_RIGHT 11
    #define SPARK           12
    #define ELECTRICITY     13
    #define LEAF            14

typedef struct particle_s {
    sfVector2f pos;
    sfVector2f trajectory;
    sfVector2f velocity;
    sfVector2f scale;
    object_t *object;
    int age;
    int lifetime;
    int type;
    float speed;
    float rotation;
    struct particle_s *next;
} particle_t;

particle_t *leaf_fragment(sfRenderWindow *window, particle_t *part);

particle_t *elctric_pulse(sfRenderWindow *window, particle_t *part);

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
