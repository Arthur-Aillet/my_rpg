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
    #define SMOOTHY (part->pos.y - SFSGP(part->object->sprite).y) / 10
    #define SMOOTHX (part->pos.x - SFSGP(part->object->sprite).x) / 10
    #define TRANSPARENT(x) sfColor_fromRGBA(255, 255, 255, x)

typedef struct particle{
    sfVector2f pos;
    sfVector2f trajectory;
    sfVector2f velocity;
    sfVector2f scale;
    object *object;
    int age;
    int lifetime;
    int type;
    float speed;
    float rotation;
    struct particle *next;
} particle;

particle *spark(sfRenderWindow *window, particle *part);

particle *rain(sfRenderWindow *window, particle *part);

particle *snow(sfRenderWindow *window, particle *part);

particle *fire(sfRenderWindow *window, particle *part);
particle *fire_up(sfRenderWindow *window, particle *part);
particle *fire_ur(sfRenderWindow *window, particle *part);
particle *fire_right(sfRenderWindow *window, particle *part);
particle *fire_dr(sfRenderWindow *window, particle *part);

particle *dust_circle(sfRenderWindow *window, particle *part);
particle *dust_up(sfRenderWindow *window, particle *part);
particle *dust_ur(sfRenderWindow *window, particle *part);
particle *dust_right(sfRenderWindow *window, particle *part);
particle *dust_dr(sfRenderWindow *window, particle *part);

void update_particles(sfRenderWindow *window, struct particle *start);
struct particle *create_particle(sfVector2f pos, int type, int speed);
struct particle *add_particle(struct particle *first, sfVector2f pos, int, int);
void exterminate(struct particle *first);
void remove_particle(particle *previous);

#endif /* !PARTICLES_STRUCTURES_H_ */
