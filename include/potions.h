/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** potions
*/

#ifndef POTIONS_H_
    #define POTIONS_H_

    #include "my_csfml_utils.h"

typedef struct minigame_s {
    object *hammer;
    object *anvil;
    object *background;
    object *box_bar;
    object *for_bar;
    object *circle_full;
    object *circle_empty;
    int has_spawn;
    float points;
} minigame_t;

typedef struct potion_s {
    int difficulty;
    int current_step;
    int numbers_steps;
} potion_t;

void destroy_minigame_struct(minigame_t *hammer);
minigame_t *setup_hammer_struct(void);
minigame_t *setup_elements(void);
void hammer_loop(window_t *window, int *keys, sound_t **sound, object *mouse, potion_t *potion);
void mortar_loop(window_t *window, int *keys, sound_t **sounds, object *mouse, potion_t *potion);
#endif /* !POTIONS_H_ */
