/*
** EPITECH PROJECT, 2021
** MAIN_C
** File description:
** main
*/

#include "my_rpg.h"

int main(int ac, char **av)
{
    if (my_error_handling(ac, av))
        return 84;
    if (my_strcmp(av[1], "-h") == 0)
        return my_help();
    if (my_window(ac, av) == 84)
        return 84;
    return 0;
}
