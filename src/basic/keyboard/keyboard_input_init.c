/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** event
*/

#include "keyboard.h"

#include <SFML/Window.h>
#include <stdlib.h>

char *init_keys(void)
{
    char *keys = malloc(sizeof(int) * (sfKeyCount + 4));

    for (int i = 0; i < sfKeyCount + 4; i++)
        keys[i] = 0;
    return keys;
}
