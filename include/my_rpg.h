/*
** EPITECH PROJECT, 2022
** MY_PROJECT_H
** File description:
** MY_PROJECT_H
*/

#ifndef MY_PROJECT_H
    #define MY_PROJECT_H

    #include "my.h"
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <assert.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/mman.h>

int my_error_handling(int ac, char **av);
int my_help(void);

int my_window(int ac, char **av);

#endif /* !MY_PROJECT_H */
