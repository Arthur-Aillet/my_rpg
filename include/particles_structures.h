/*
** EPITECH PROJECT, 2022
** rpg - particles structures
** File description:
** here be explenations
*/

#pragma once

#include <csfml_libs.h>

struct particle{
    sfVector2f pos;
    sfVector2f trajectory;
    sfVector2f velocity;
    sfVector2f scale;
    int age;
    int lifetime;
    int type;
    float speed;
    struct particle *next;
};
