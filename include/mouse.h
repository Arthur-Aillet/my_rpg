/*
** EPITECH PROJECT, 2022
** my_rpg_temp
** File description:
** mouse
*/

#ifndef MOUSE_H_
    #define MOUSE_H_

    #include "csfml_libs.h"

    struct object setup_mouse(void);
    void draw_mouse(sfRenderWindow *window, sfSprite *mouse);
    void free_object(struct object object);

#endif /* !MOUSE_H_ */
