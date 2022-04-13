/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** minigame
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>

#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "my_rpg.h"
#include "potions.h"
#include "my_mouse.h"
#include "my_button.h"
#include "particles.h"
#include "my_event.h"
#include "my_csfml_utils.h"
#include "particles_structures.h"

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
