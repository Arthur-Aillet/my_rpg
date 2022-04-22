/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_text
*/

#pragma once

#define FONT(name, fonts) font_from_array_font(name, fonts)
#define FONTG(font) find_font(font, game->fonts)

#include <SFML/Graphics.h>

typedef struct font_s {
    char *name;
    sfFont *font;
} font_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
} text_t;

font_t **font_create_array(void);
sfFont *find_font(char *name, font_t **fonts);
text_t *text_setup_with_font(char *string, sfFont *font, int char_size);
void text_destroy(text_t *text);
text_t *text_setup(char *string, char *font, int char_size);
