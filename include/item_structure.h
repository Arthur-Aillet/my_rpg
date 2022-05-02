/*
** EPITECH PROJECT, 2022
** rpg - item structure
** File description:
** here be definition
*/

#pragma once

#include "my_csfml_utils.h"

typedef struct item_s {
    object_t *obj;
    int quantity;
    int stack_size;
    int type;
    int armor_type;
    void (*action)(void *);
} item_t;
