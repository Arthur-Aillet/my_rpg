/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_window
*/

#ifndef MY_WINDOW_H_
    #define MY_WINDOW_H_

    #include <SFML/Graphics.h>
    #include <stdbool.h>

/*

type 0 = Fenetre normale
type 1 = Fenetre sans bord
type 2 = Fenetre plein ecran

*/

typedef struct window_s {
    sfRenderWindow *window;
    char *icon_file;
    char *name;
    int height;
    int width;
    int framerate;
    bool vsync;
    int type;
} window_t;

void create_windows(window_t *window);
void create_icon(window_t *window);
window_t *generate_default_window(void);
void free_window_struct(window_t *window);

#endif /* !MY_WINDOW_H_ */
