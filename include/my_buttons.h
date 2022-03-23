/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_buttons
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #include "csfml.h"
    #include "structs.h"

    #include <stdbool.h>

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *texture;
    int already_hoverd;
    sfSound *hover;
    sfSoundBuffer *hover_buf;
    sfSound *click;
    sfSoundBuffer *click_buf;
    text text;
} button;

void setup_button_text(button *, char *, char *, int);
button create_button(sfVector2f, sfVector2f, bool);
void setup_button_texture(button *, sfIntRect *, char *);
void setup_button_sounds(button *bouton, char *click, char *hover, env_t *env);

void center_button_text(button *);
void display_button(sfRenderWindow *, button *, int *);
void destroy_button(button);
sfBool is_pressed(button, sfRenderWindow *, int *);

#endif
