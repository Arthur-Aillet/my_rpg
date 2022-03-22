/*
** EPITECH PROJECT, 2022
** MY_WINDOW_STRUCT_H
** File description:
** my_window
*/

#ifndef MY_WINDOW_H_
    #define MY_WINDOW_H_

typedef struct window_s {
    sfRenderWindow *window;
    int height;
    int width;
    int framerate;
} window_t;

#endif /* !MY_WINDOW_H_ */
