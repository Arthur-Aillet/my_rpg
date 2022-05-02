/*
** EPITECH PROJECT, 2022
** rpg - particles structures
** File description:
** here be explenations
*/

#pragma once

#include <csfml_libs.h>
#include "my_csfml_utils.h"
#include "my_rpg.h"
#include "particle_struct.h"

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
#define LIGHT_DUST      15
#define MAGIC_VIBE      16

particle_t *magic_vibe(sfRenderWindow *window, particle_t *part, sfClock *);

particle_t *leaf_fragment(sfRenderWindow *window, particle_t *part, sfClock *);
particle_t *light_dust(sfRenderWindow *window, particle_t *part, sfClock *);

particle_t *elctric_pulse(sfRenderWindow *window, particle_t *part, sfClock *);

particle_t *spark(sfRenderWindow *window, particle_t *part, sfClock *);

particle_t *rain(sfRenderWindow *window, particle_t *part, sfClock *);

particle_t *snow(sfRenderWindow *window, particle_t *part, sfClock *);

particle_t *fire(sfRenderWindow *window, particle_t *part, sfClock *);
particle_t *fire_up(sfRenderWindow *window, particle_t *part, sfClock *);
particle_t *fire_ur(sfRenderWindow *window, particle_t *part, sfClock *);
particle_t *fire_right(sfRenderWindow *window, particle_t *part, sfClock *);
particle_t *fire_dr(sfRenderWindow *window, particle_t *part, sfClock *);

particle_t *dust_circle(sfRenderWindow *window, particle_t *part, sfClock *);
particle_t *dust_up(sfRenderWindow *window, particle_t *part, sfClock *);
particle_t *dust_ur(sfRenderWindow *window, particle_t *part, sfClock *);
particle_t *dust_right(sfRenderWindow *window, particle_t *part, sfClock *);
particle_t *dust_dr(sfRenderWindow *window, particle_t *part, sfClock *);

void update_particles(sfRenderWindow *window,
particle_t *start);
particle_t *create_particle(sfVector2f pos, int type, int speed);
particle_t *add_particle(particle_t *first, sfVector2f pos, int type, int spd);
void exterminate(particle_t *first);
void remove_particle(particle_t *previous);
