/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** minigame
*/

#include <stdlib.h>

#include "potions.h"
#include "my_csfml_utils.h"

void destroy_minigame_struct(minigame_t *structure)
{
    destroy_object(structure->anvil);
    destroy_object(structure->background);
    destroy_object(structure->hammer);
    destroy_object(structure->for_bar);
    destroy_object(structure->box_bar);
    destroy_object(structure->circle_full);
    destroy_object(structure->circle_empty);
    free(structure);
}
