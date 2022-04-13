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
    #include "my_text.h"
    #include "my_sound.h"
    #include "my_csfml_utils.h"

typedef struct game_s {
    char *keys;
    control_t *status;
    window_t *window;
    object_t *mouse;
    font_t **fonts;
    sound_t **sounds;
} game_t;

#endif /* !MY_GAME_STRUCT_H_ */
