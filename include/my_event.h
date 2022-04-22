/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_event
*/

#pragma once

#include "my_window_struct.h"

#define leftMouse 101
#define rightMouse 102

#define PRESS 1
#define HOLD 2
#define RELEASED 3

#define CLICKED (keys[leftMouse] == 1 || keys[leftMouse] == 2)

#define evntMousePressed event.type == sfEvtMouseButtonPressed
#define evntMouseReleased event.type == sfEvtMouseButtonReleased

void evolve_mouse(int *keys);
int *get_events(sfRenderWindow *window, int *keys);
int *init_keys(void);
