/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** potions
*/

#ifndef POTIONS_H_
    #define POTIONS_H_

    #include "my_csfml_utils.h"

typedef struct hammer_s {
    object *hammer;
    object *anvil;
    object *background;
    object *box_bar;
    object *for_bar;
    object *circle_full;
    object *circle_empty;
    int has_spawn;
    float points;
} hammer_t;

void hammer_loop(window_t *window, int *keys, object *mouse, int difficulty);

#endif /* !POTIONS_H_ */
