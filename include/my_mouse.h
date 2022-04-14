/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_mouse
*/

#pragma once

#include "my_csfml_utils.h"

void update_mouse_cursor(sfRenderWindow *window, object_t *mouse);
sfVector2f get_global_mouse_pos(sfRenderWindow *window);
