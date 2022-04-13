/*
** EPITECH PROJECT, 2022
** rpg - inventory structures
** File description:
** dere be definitions
*/


#ifndef INVENTORY_STRUCTURES_H_
    #define INVENTORY_STRUCTURES_H_

    #include "csfml_libs.h"
    #include "my_csfml_utils.h"

    typedef struct competences_s {
        int dodge_roll;
        int fireball;
    } competences_t;

    typedef struct item_s {
        sfSprite *sprite;
        sfTexture *texture;
        int quantity;
        int stack_size;
        int type;
        int armor_type;
    } item_t;

    typedef struct txtobject_s {
        sfText *text;
        sfFont *font;
    } txtobject_t;

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
        competences_t *comp;
    } events_t;

#endif /* !INVENTORY_STRUCTURES_H_ */
