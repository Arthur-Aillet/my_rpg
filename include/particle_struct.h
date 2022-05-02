/*
** EPITECH PROJECT, 2022
** rpg particle structure
** File description:
** here be description
*/

#pragma once

#include "csfml_libs.h"
#include "my_csfml_utils.h"

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
