/*
** EPITECH PROJECT, 2022
** rpg - particles structures
** File description:
** here be explenations
*/

#include <csfml_libs.h>

#ifndef PARTICLES_STRUCTURES_H_
    #define PARTICLES_STRUCTURES_H_

struct particle{
    sfVector2f pos;
    sfVector2f trajectory;
    sfVector2f velocity;
    sfVector2f scale;
    int age;
    int lifetime;
    int type;
    int speed;
    struct particle *next;
};

#endif /* !PARTICLES_STRUCTURES_H_ */
