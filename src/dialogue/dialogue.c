/*
** EPITECH PROJECT, 2022
** rpg - dialogue
** File description:
** they do be talking
*/

#include "my_csfml_utils.h"
#include "json.h"
#include "dialogue.h"
#include "keyboard.h"
#include "my_text.h"
#include <stdlib.h>

static void draw_pic(sfRenderWindow *window, object *pic, int direction)
{
    sfVector2f pos = {36, 664};
    sfVector2f size = {240, 376};

    if (direction != 0)
        pos.x = 1644;
    sfSprite_setPosition(pic->sprite, pos);
    sf_sprite_set_pixel_size(pic->sprite, size);
    sfRenderWindow_drawSprite(window, pic->sprite, NULL);
}

static void draw_name(sfRenderWindow *window, char *name, int dir, sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f pos = {304, 688};
    sfVector2f size = {200, 44};

    if (dir != 0)
        pos.x = 1416;
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setString(text, name);
    sf_text_set_pixel_size(text, size);
    sfRenderWindow_drawText(window, text, NULL);
}

static void draw_line(sfRenderWindow *window, char *line, int dir, sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f pos = {332, 756};
    sfVector2f size = {1544, 248};

    if (dir != 0)
        pos.x = 64;
    line = add_new_lines(line);
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setString(text, line);
    sf_text_set_pixel_size(text, size);
    sfRenderWindow_drawText(window, text, NULL);
}

static void display_line(sfRenderWindow *window, json_obj_t *obj, font_t **fonts)
{
    sfVector2f none = {0, 0};
    sfFont *font = find_font(get_str_by_name(obj, "font"), fonts);
    object *pic = create_object(get_str_by_name(obj, "immage"), none, none);
    int direction = get_int_by_name(obj, "direction");

    draw_chatbox(window, direction);
    draw_pic(window, pic, direction);
    draw_name(window, get_str_by_name(obj, "name"), direction, font);
    draw_line(window, get_str_by_name(obj, "text"), direction, font);
    destroy_object(pic);
}

void display_dialogue(sfRenderWindow *window, char *path, char *keys, font_t **fonts)
{
    static int step = 0;
    json_obj_t *json = create_json_object(path);
    json_obj_t *obj = get_obj_by_index(json, step);

    if (ENTER == 2)
        step += 1;
    if (obj != NULL)
        display_line(window, obj, fonts);
}