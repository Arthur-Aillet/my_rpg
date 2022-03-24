/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_text
*/

#ifndef MY_TEXT_H_
    #define MY_TEXT_H_

    #define FONT(name, fonts) font_from_array_font(name, fonts)

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
sfFont *font_from_array_font(char *name, font_t **fonts);
text_t *text_setup_with_font(char *string, sfFont *font, int char_size);
void text_destroy(text_t *text);
text_t *text_setup(char *string, char *font, int char_size);

#endif /* !MY_TEXT_H_ */
