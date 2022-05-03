/*
** EPITECH PROJECT, 2022
** INIT_GAME_STATUS_C
** File description:
** init_game_status
*/

#include <stdlib.h>
#include <stddef.h>
#include "my_controle_struct.h"

control_t *init_game_status(void)
{
    control_t *control = malloc(sizeof(control_t));

    if (control == NULL)
        return NULL;
    control->end_game = 0;
    control->end_pause = 0;
    control->status = 0;
    return control;
}
