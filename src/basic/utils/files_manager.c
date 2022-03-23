/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** files_manager
*/

#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

int count_files_in_folder(char *name)
{
    int conti = 1;
    int nbr = 0;
    DIR *fd = opendir(name);
    struct dirent *dir;

    if (fd == NULL)
        return (-1);
    for (int i = 0; conti == 1; i++) {
        dir = readdir(fd);
        if (dir == NULL)
            conti = 0;
        if (dir != NULL && dir->d_name[0] != '.')
            nbr += 1;
    }
    closedir(fd);
    return (nbr);
}

bool does_file_exist(char *name)
{
    FILE *file;

    file = fopen(name, "r");
    if (file == NULL)
        return false;
    fclose(file);
    return true;
}
