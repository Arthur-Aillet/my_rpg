/*
** EPITECH PROJECT, 2022
** MY_GAME_STRUCT_H
** File description:
** my_game_struct
*/

#ifndef MY_GAME_STRUCT_H_
    #define MY_GAME_STRUCT_H_

#include "my_window_struct.h"
#include "my_controle_struct.h"

typedef struct game_s {
    control_t *status;
    window_t *my_window;
} game_t;

#endif /* !MY_GAME_STRUCT_H_ */
