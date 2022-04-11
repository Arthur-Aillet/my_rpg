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

    struct competences {
        int dodge_roll;
        int fireball;
    };

    struct item {
        sfSprite *sprite;
        sfTexture *texture;
        int quantity;
        int stack_size;
        int type;
        int armor_type;
    };

    struct txtobject {
        sfText *text;
        sfFont *font;
    };

    struct backgrounds {
        sfRenderWindow *window;
        struct item *items;
        object **pages;
        struct txtobject text;
        char *keys;
        struct competences *comp;
    };

    struct events {
        sfRenderWindow *window;
        struct item *items;
        int *page;
        char *keys;
        struct competences *comp;
    };

#endif /* !INVENTORY_STRUCTURES_H_ */
