/*
** EPITECH PROJECT, 2022
** my_rpg_main_2
** File description:
** pnjs
*/

#pragma once

#include "my_csfml_utils.h"

void destroy_pnjs(pnj_t **pnjs);
pnj_t **create_pnjs(void);
void create_pnj(json_obj_t *obj);
void display_pnjs(game_t *game);
pnj_t *find_pnj(char *pnj, game_t *game);
void display_dialogues(game_t *game);
