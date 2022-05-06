/*
** EPITECH PROJECT, 2021
** MAIN_C
** File description:
** main
*/

#include "my_rpg.h"
#include "my.h"
#include "json.h"
int main(int ac, char **av)
{
    if (my_error_handling(ac, av))
        return 84;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return my_help();
    if (my_rpg() == 84)
        return 84;
    return 0;
}
