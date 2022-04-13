/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_sound
*/

#pragma once

#include <SFML/Audio.h>

typedef struct sound_s {
    char *name;
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

sfSound *find_sound(char *name, sound_t **sounds);
sound_t **sounds_create_array(void);
