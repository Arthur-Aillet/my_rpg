/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** fonts
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <dirent.h>

#include "my_text.h"
#include "my.h"
#include "my_files.h"

sfFont *font_from_array_font(char *name, font_t **fonts)
{
    for (int i = 0; fonts[i] != NULL; i++)
        if (fonts[i]->name == name)
            return (fonts[i]->font);
    return (NULL);
}

void fill_fonts(DIR *fd, font_t **fonts)
{
    int conti = 1;
    int number = 0;
    char *name;
    struct dirent *dir;

    for (int i = 0; conti == 1; i++) {
        dir = readdir(fd);
        if (dir == NULL)
            conti = 0;
        if (dir != NULL && dir->d_name[0] != '.') {
            name = malloc(sizeof(char) * (13 + my_strlen(dir->d_name)));
            name = my_strcpy(name, "assets/font/");
            name = my_strcat(name, dir->d_name);
            fonts[number] = malloc(sizeof(font_t));
            fonts[number]->font = sfFont_createFromFile(name);
            fonts[number]->name = my_strdup(dir->d_name);
            number += 1;
            free(name);
        }
    }
}

font_t **font_create_array(void)
{
    int nbr_files = count_files_in_folder("assets/font");
    font_t **fonts;
    DIR *fd = opendir("assets/font");

    if (nbr_files == -1 || fd == NULL)
        return (NULL);
    fonts = malloc(sizeof(font_t *) * (nbr_files + 1));
    if (fd == NULL || fonts == NULL)
        return (NULL);
    fill_fonts(fd, fonts);
    fonts[nbr_files] = NULL;
    closedir(fd);
    return fonts;
}
