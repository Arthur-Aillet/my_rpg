/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** potions
*/

#ifndef POTIONS_H_
    #define POTIONS_H_

    #include "my_csfml_utils.h"
    #include "my_rpg.h"

typedef struct minigame_s {
    object_t *hammer;
    object_t *anvil;
    object_t *background;
    object_t *box_bar;
    object_t *for_bar;
    object_t *circle_full;
    object_t *circle_empty;
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
void potion_loop(game_t *game);
void hammer_loop(game_t *game, potion_t *potion);
void mortar_loop(game_t *game, potion_t *potion);

#endif /* !POTIONS_H_ */
