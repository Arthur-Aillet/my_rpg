/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** sound
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <dirent.h>

#include "my.h"
#include "my_sound.h"
#include "my_files.h"

sfSound *find_sound(char *name, sound_t **sounds)
{
    if (sounds == NULL)
        return (NULL);
    for (int i = 0; sounds[i] != NULL; i++)
        if (my_strcmp(sounds[i]->name, name) == 0)
            return (sounds[i]->sound);
    return (NULL);
}

void fill_sounds(DIR *fd, sound_t **sounds, char *name, struct dirent *dir)
{
    int conti = 1;
    int number = 0;

    for (int i = 0; conti == 1; i++) {
        dir = readdir(fd);
        if (dir == NULL)
            conti = 0;
        if (dir != NULL && dir->d_name[0] != '.') {
            name = malloc(sizeof(char) * (14 + my_strlen(dir->d_name)));
            name = my_strcpy(name, "assets/sound/");
            name = my_strcat(name, dir->d_name);
            sounds[number] = malloc(sizeof(sound_t));
            sounds[number]->buffer = sfSoundBuffer_createFromFile(name);
            sounds[number]->sound = sfSound_create();
            sfSound_setBuffer(sounds[number]->sound, sounds[number]->buffer);
            sounds[number]->name = my_strdup(dir->d_name);
            number += 1;
            free(name);
        }
    }
}

sound_t **sounds_create_array(void)
{
    int nbr_files = count_files_in_folder("assets/sound");
    sound_t **sounds;
    DIR *fd = opendir("assets/sound");
    char *name = NULL;
    struct dirent *dir = NULL;

    if (nbr_files == -1 || fd == NULL)
        return (NULL);
    sounds = malloc(sizeof(sound_t *) * (nbr_files + 1));
    if (fd == NULL || sounds == NULL)
        return (NULL);
    fill_sounds(fd, sounds, name, dir);
    sounds[nbr_files] = NULL;
    closedir(fd);
    return sounds;
}
