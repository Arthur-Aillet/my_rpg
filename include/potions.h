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
    #include "particles.h"

typedef struct minigame_s {
    object_t *hammer;
    object_t *anvil;
    object_t *mortar_front;
    object_t *mortar_back;
    object_t *leaves;
    object_t *pilon;
    object_t *background;
    object_t *box_bar;
    object_t *for_bar;
    object_t *circle_full;
    object_t *circle_empty;
    sfTexture *leaves1;
    sfTexture *leaves2;
    sfTexture *leaves3;
    int has_spawn;
    int step;
    float points;
    sfSound *sound;
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
minigame_t *setup_elements(void);
minigame_t *setup_hammer_struct(void);
void hammer_controls(minigame_t *elements, particle_t **start, char *keys, sfSound *sound);
void display_hammer(minigame_t *eleme, window_t *window, potion_t *pot);
int hammer_update(char *keys, minigame_t *elements, potion_t *pot, sfClock *clock);
void display_minigame(minigame_t *eleme, window_t *window, potion_t *pot);
int minigame_update(char *keys, minigame_t *elements, potion_t *pot, sfClock *clock);

#endif /* !POTIONS_H_ */
