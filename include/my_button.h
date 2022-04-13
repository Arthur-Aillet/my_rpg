/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_buttons
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#include "my_text.h"

typedef struct button_s {
    sfVector2f scale_hover;
    sfVector2f scale_click;
    text_t text;
    bool display_text;
    sfSprite *sprite;
    sfTexture *texture;
    sfSound *hover;
    sfSoundBuffer *hover_buf;
    sfSound *click;
    sfSoundBuffer *click_buf;
    bool already_hoverd;
    bool already_clicked;
} button_t;

bool is_pressed(button_t bouton, sfRenderWindow *window, int *keys);
button_t *button_create(sfVector2f size, sfVector2f position, bool display_tex);
void button_setup_texture(button_t *bouton, sfIntRect size, char *file_name);
void button_setup_text_file(button_t *bouton, char *text, char *font, int size);
void button_setup_text(button_t *bouton, char *text, sfFont *font, int size);
void button_setup_sounds_file(button_t *but, char *click, char *hover, int vol);
void button_center_text(button_t *bouton);
void button_update_state(sfVector2f mouse_pos, button_t *but, int *keys);
void display_button(sfRenderWindow *window, button_t *but);
void update_button(sfRenderWindow *window, button_t *but, int *keys);
void destroy_button(button_t bouton);
void button_setup_sounds(button_t *but, sfSound *click, sfSound *hover, int vo);
void button_setup_offset(button_t *bouton, sfVector2f hover, sfVector2f click);
