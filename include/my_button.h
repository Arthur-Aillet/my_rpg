/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_buttons
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>

    #include "my_text.h"

typedef struct button_s {
    sfFloatRect displacement_hover;
    sfFloatRect displacement_click;
    text_t text;
    bool display_text;
    sfSprite *sprite;
    sfTexture *texture;
    sfSound *hover;
    sfSoundBuffer *hover_buf;
    sfSound *click;
    sfSoundBuffer *click_buf;
    int already_hoverd;
} button_t;

void button_center_text(button_t *bouton);

#endif
