/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** text
*/

#include <SFML/Graphics.h>

#include "my_text.h"
#include "my.h"

text_t *text_setup_with_font(char *string, sfFont *font, int char_size)
{
    text_t *texte = malloc(sizeof(text_t));

    texte->text = sfText_create();
    texte->font = font;
    if (font != NULL)
        sfText_setFont(texte->text, texte->font);
    sfText_setString(texte->text, string);
    sfText_setCharacterSize(texte->text, char_size);
    return (texte);
}

text_t *text_setup(char *string, char *font, int char_size)
{
    text_t *texte = malloc(sizeof(text_t));

    texte->text = sfText_create();
    texte->font = sfFont_createFromFile(font);
    sfText_setFont(texte->text, texte->font);
    sfText_setString(texte->text, string);
    sfText_setCharacterSize(texte->text, char_size);
    return (texte);
}

void text_destroy(text_t *text)
{
    sfText_destroy(text->text);
    sfFont_destroy(text->font);
    free(text);
}
