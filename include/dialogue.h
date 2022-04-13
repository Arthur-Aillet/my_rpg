/*
** EPITECH PROJECT, 2022
** rpg - dialogue
** File description:
** here be definitions
*/

#ifndef DIALOGUE_H_
    #define DIALOGUE_H_

    #include "csfml_libs.h"

char *add_new_lines(char *str);
void draw_chatbox(sfRenderWindow *window, int direction);
void sf_text_set_pixel_size(sfText *text, sfVector2f size);
void sf_sprite_set_pixel_size(sfSprite *sprite, sfVector2f size);
void display_dialogue(sfRenderWindow *window, char *path, char *, font_t **);
char *add_new_lines(char *str);

#endif /* !DIALOGUE_H_ */
