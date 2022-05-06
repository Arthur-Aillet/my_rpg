/*
** EPITECH PROJECT, 2022
** rpg - inventory structures
** File description:
** dere be definitions
*/

#pragma once

#include "csfml_libs.h"
#include "my_csfml_utils.h"
#include "my_game_struct.h"

typedef struct competences_s {
    int dodge_roll;
    int fireball;
    int c3;
    int c4;
    int c5;
    int c6;
    int c7;
    int c8;
    int c9;
    int c10;
    int c11;
    int c12;
    int c13;
    int c14;
    int c15;
    int c16;
    int c17;
    int c18;
    int c19;
    int c20;
    int c21;
    int c22;
    int c23;
    int c24;
    int c25;
    int c26;
    int c27;
    int c28;
    int c29;
    int c30;
    int c31;
    int c32;
    int c33;
    int c34;
    int c35;
    int c36;
    int c37;
    int c38;
    int c39;
    int c40;
    int c41;
    int c42;
    int c43;
    int c44;
    int c45;
    int c46;
    int c47;
    int c48;
    int c49;
    int c50;
    int c51;
    int c52;
    int c53;
    int c54;
    int c55;
    int c56;
    int c57;
    int c58;
    int c59;
    int c60;
    int c61;
    int c62;
    int c63;
    int c64;
    int c65;
    int c66;
    int c67;
    object_t **sprites;
    int comp_points;
} competences_t;

competences_t set_competence_six(int comp, competences_t comps, int st);

typedef struct txtobject_s {
    sfText *text;
    sfFont *font;
} txtobject_t;

typedef struct game_s game_t;

typedef struct item_s {
    object_t *obj;
    int quantity;
    int stack_size;
    int type;
    int armor_type;
    void (*action)(game_t *);
    int consumable;
    int power;
} item_t;

typedef struct backgrounds_s {
    sfRenderWindow *window;
    item_t *items;
    object_t **pages;
    txtobject_t text;
    char *keys;
    competences_t *comp;
} backgrounds_t;

typedef struct events_s {
    sfRenderWindow *window;
    item_t *items;
    int *page;
    char *keys;
    struct button_s *button;
    competences_t *comp;
} events_t;
