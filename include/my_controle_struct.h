/*
** EPITECH PROJECT, 2022
** MY_CONTROL_STRUC_H
** File description:
** my_controle_struct
*/

#ifndef MY_CONTROLE_STRUCT_H_
    #define MY_CONTROLE_STRUCT_H_

#include <stdbool.h>

typedef struct control_s {
    bool status;
    bool end_pause;
    bool end_game;
} control_t;

#endif /* !MY_CONTROLE_STRUCT_H_ */
