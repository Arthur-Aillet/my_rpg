/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event
*/

#include "my_event.h"

#include <SFML/Window.h>
#include <stdlib.h>

int *init_keys(void)
{
    int *keys = malloc(sizeof(int) * (sfKeyCount + 2));

    for (int i = 0; i < sfKeyCount + 2; i++)
        keys[i] = 0;
    return keys;
}

void evolve_mouse(int *keys)
{
    if (keys[leftMouse] == PRESS || keys[leftMouse] == RELEASED)
        keys[leftMouse] = (keys[leftMouse] + 1) % 4;
    if (keys[rightMouse] == PRESS || keys[rightMouse] == RELEASED)
        keys[rightMouse] = (keys[rightMouse] + 1) % 4;
}

void evolve_keys(int *keys)
{
    for (int i = 0; i < sfKeyCount; i++) {
        if (sfKeyboard_isKeyPressed(i) == sfTrue && keys[i] == 1)
            keys[i]++;
        if (sfKeyboard_isKeyPressed(i) == sfTrue && keys[i] == 0)
            keys[i]++;
        if (sfKeyboard_isKeyPressed(i) == sfFalse && keys[i] == 3)
            keys[i] = 0;
        if (sfKeyboard_isKeyPressed(i) == sfFalse && keys[i] > 0 && keys[i] < 3)
            keys[i] = 3;
    }
}

int *get_events(sfRenderWindow *window, int *keys)
{
    sfEvent event;

    evolve_mouse(keys);
    evolve_keys(keys);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (evntMousePressed && event.mouseButton.button == sfMouseLeft)
            keys[leftMouse] = PRESS;
        if (evntMouseReleased && event.mouseButton.button == sfMouseLeft)
            keys[leftMouse] = RELEASED;
        if (evntMousePressed && event.mouseButton.button == sfMouseRight)
            keys[rightMouse] = PRESS;
        if (evntMouseReleased && event.mouseButton.button == sfMouseRight)
            keys[rightMouse] = RELEASED;
    }
    return keys;
}
