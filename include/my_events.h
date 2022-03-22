/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** events.h
*/

#ifndef EVENTS_H
    #define EVENTS_H

    #include "my_window_struct.h"

    #define leftMouse 101
    #define rightMouse 102

    #define press 1
    #define hold 2
    #define release 3

    #define evntMousePressed event.type == sfEvtMouseButtonPressed
    #define evntMouseReleased event.type == sfEvtMouseButtonReleased

void evolve_mouse(int *keys);
int *get_events(sfRenderWindow *window, int *keys);
int *init_keys(void);

#endif
