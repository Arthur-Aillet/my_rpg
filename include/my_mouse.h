/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_mouse
*/

#ifndef MY_MOUSE_H_
    #define MY_MOUSE_H_

    #include "my_csfml_utils.h"

void update_mouse_cursor(sfRenderWindow *window, object *mouse);
sfVector2f get_global_mouse_pos(sfRenderWindow *window);

#endif /* !MY_MOUSE_H_ */
