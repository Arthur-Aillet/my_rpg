/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_sound
*/

#pragma once

#include <SFML/Audio.h>

#define SOUNDG(sound) find_sound(sound, game->sounds)
#define MUSICG(music) find_music(music, game->musics)

typedef struct music_s {
    char *name;
    sfMusic *music;
} music_t;

typedef struct sound_s {
    char *name;
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

music_t **musics_create_array(void);
sfSound *find_sound(char *name, sound_t **sounds);
sound_t **sounds_create_array(void);
sfMusic *find_music(char *name, music_t **musics);
