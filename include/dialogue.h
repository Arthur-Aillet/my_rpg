/*
** EPITECH PROJECT, 2022
** rpg - dialogue
** File description:
** here be definitions
*/

#pragma once

#include "csfml_libs.h"
#include "my_text.h"

char *add_new_lines(char *str);
void draw_chatbox(sfRenderWindow *window, int direction);
void display_dialogue(game_t *game, char *path, int *, font_t **);
char *add_new_lines(char *str);
