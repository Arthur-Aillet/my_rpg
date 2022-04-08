/*
** EPITECH PROJECT, 2022
** Armory - get keyboard input
** File description:
** returns a char * with the keyboard key pressed
*/

#include "csfml_libs.h"
#include "keyboard.h"

#include <stdlib.h>

static char *press_buttons(sfEvent event, char *keys, int state)
{
    for (int i = 0; i <= sfKeyCount; i++)
        if (i == event.key.code)
            keys[i] = state;
    return (keys);
}

static char *cleanup_keys(char *keys)
{
    for (int i = 0; i <= sfKeyCount + 2; i++) {
        if (keys[i] == PRESS)
            keys[i] = HELD;
        if (keys[i] == RELEASE)
            keys[i] = NHELD;
    }
    HSCROLL = 0;
    VSCROLL = 0;
    return (keys);
}

static char *get_click(sfEvent event, char *keys)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == 0)
            LCLICK = PRESS;
        if (event.mouseButton.button == 1)
            RCLICK = PRESS;
    }
    if (event.type == sfEvtMouseButtonReleased) {
        if (event.mouseButton.button == 0)
            LCLICK = RELEASE;
        if (event.mouseButton.button == 1)
            RCLICK = RELEASE;
    }
    return (keys);
}

static char *get_scroll(sfEvent event, char *keys)
{
    static float previouser = 0;
    static float previous = 0;
    float current = 0;

    current = event.mouseWheelScroll.delta;
    if (ABS(current) >= 1 && ABS(previous) < 1 && ABS(previouser) >= 1)
        VSCROLL = current;
    if (ABS(current) < 1 && ABS(previous) >= 1 && ABS(previouser) < 1)
        VSCROLL = previous;
    if (ABS(current) >= 1 && ABS(previous) >= 1 && ABS(previouser) >= 1)
        HSCROLL = current;
    previouser = previous;
    previous = current;
    return (keys);
}

char *get_keyboard_input(sfEvent event, char *keys, sfRenderWindow *window)
{
    cleanup_keys(keys);
    while (sfRenderWindow_pollEvent(window, &event)) {
        keys = get_click(event, keys);
        keys = get_scroll(event, keys);
        if (event.type == sfEvtKeyPressed)
            keys = press_buttons(event, keys, PRESS);
        if (event.type == sfEvtKeyReleased)
            keys = press_buttons(event, keys, RELEASE);
    }
    return (keys);
}
