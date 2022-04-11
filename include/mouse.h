/*
** EPITECH PROJECT, 2022
** my_rpg_temp
** File description:
** mouse
*/

#ifndef MOUSE_H_
    #define MOUSE_H_

    #include "csfml_libs.h"
    #include "my_csfml_utils.h"

    void draw_mouse(sfRenderWindow *window, sfSprite *mouse);
    void free_object(object object);

#endif /* !MOUSE_H_ */
