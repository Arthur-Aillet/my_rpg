/*
** EPITECH PROJECT, 2022
** rpg - dialogue utils
** File description:
** itty bitty functions for the dialogues
*/

#include "csfml_libs.h"
#include "my_csfml_utils.h"
#include <stdlib.h>

static char *remove(char *str, int pos)
{
    int i = pos;
    for (; str[i + 1] != '\0'; i++)
        str[i] = str[i + 1];
    str[i] = '\0';
    return (str);
}

char *add_new_lines(char *str)
{
    for (int i = 0; str[i + 1] != '\0'; i++) {
        if (str[i] == '\\' && str[i + 1] == 'n') {
            str[i] = '\n';
            str = remove(str, i + 1);
        }
    }
    return (str);
}

void sf_sprite_set_pixel_size(sfSprite *sprite, sfVector2f size)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);
    sfVector2f scale = {size.x / rect.width, size.y / rect.height};

    sfSprite_setScale(sprite, scale);
}

void sf_text_set_pixel_size(sfText *text, sfVector2f size)
{
    sfText_setCharacterSize(text, 100);
    while (sfText_getLocalBounds(text).width > size.x)
        sfText_setCharacterSize(text, sfText_getCharacterSize(text) - 1);
    while (sfText_getLocalBounds(text).height > size.y - 10)
        sfText_setCharacterSize(text, sfText_getCharacterSize(text) - 1);
}

void draw_chatbox(sfRenderWindow *window, int direction)
{
    static object_t **textbox = NULL;
    sfVector2i pos = {0, 0};
    sfVector2f scale = {4, 4};
    sfVector2f new_pos = sfRenderWindow_mapPixelToCoords(window, pos,
        sfRenderWindow_getView(window));


    if (textbox == NULL) {
        textbox = malloc(sizeof(object_t) * 2);
        textbox[0] = create_object("assets/img/dialogue.png", new_pos, scale);
        textbox[1] = create_object("assets/img/response.png", new_pos, scale);
    }
    if (direction != 0) {
        sfSprite_setPosition(textbox[1]->sprite, new_pos);
        sfRenderWindow_drawSprite(window, textbox[1]->sprite, NULL);
        return;
    }
        sfSprite_setPosition(textbox[0]->sprite, new_pos);
    sfRenderWindow_drawSprite(window, textbox[0]->sprite, NULL);
}
