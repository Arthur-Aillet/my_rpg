/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** music
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <dirent.h>

#include "my.h"
#include "my_sound.h"
#include "my_files.h"

sfMusic *find_music(char *name, music_t **musics)
{
    if (musics == NULL)
        return (NULL);
    for (int i = 0; musics[i] != NULL; i++)
        if (my_strcmp(musics[i]->name, name) == 0)
            return (musics[i]->music);
    return (NULL);
}

void fill_musics(DIR *fd, music_t **musics, char *name, struct dirent *dir)
{
    int conti = 1;
    int number = 0;

    for (int i = 0; conti == 1; i++) {
        dir = readdir(fd);
        if (dir == NULL)
            conti = 0;
        if (dir != NULL && dir->d_name[0] != '.') {
            name = malloc(sizeof(char) * (14 + my_strlen(dir->d_name)));
            name = my_strcpy(name, "assets/music/");
            name = my_strcat(name, dir->d_name);
            musics[number] = malloc(sizeof(music_t));
            musics[number]->music = sfMusic_createFromFile(name);
            musics[number]->name = my_strdup(dir->d_name);
            number += 1;
            free(name);
        }
    }
}

music_t **musics_create_array(void)
{
    int nbr_files = count_files_in_folder("assets/music");
    music_t **musics;
    DIR *fd = opendir("assets/music");
    char *name = NULL;
    struct dirent *dir = NULL;

    if (nbr_files == -1 || fd == NULL)
        return (NULL);
    musics = malloc(sizeof(music_t *) * (nbr_files + 1));
    if (fd == NULL || musics == NULL)
        return (NULL);
    fill_musics(fd, musics, name, dir);
    musics[nbr_files] = NULL;
    closedir(fd);
    return musics;
}
