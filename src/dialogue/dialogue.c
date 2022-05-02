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
#include "my_game_struct.h"
#include <stdlib.h>

static void draw_pic(sfRenderWindow *window, object_t *pic, int direction)
{
    sfVector2i pos = {36 - 2, 664 - 12};
    sfVector2f size = {240, 376};
    sfVector2f new_pos;

    if (direction != 0)
        pos.x = 1644 - 37;
    new_pos = sfRenderWindow_mapPixelToCoords(window, pos,
        sfRenderWindow_getView(window));
    sfSprite_setPosition(pic->sprite, new_pos);
    sf_sprite_set_pixel_size(pic->sprite, size);
    sfRenderWindow_drawSprite(window, pic->sprite, NULL);
}

static void draw_name(sfRenderWindow *window, char *name, int dir, sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2i pos = {304 + 8, 688 - 23};
    sfVector2f size = {200, 44};
    sfVector2f new_pos;

    if (dir != 0)
        pos.x = 1416 - 10;
    new_pos = sfRenderWindow_mapPixelToCoords(window, pos,
        sfRenderWindow_getView(window));
    sfText_setFont(text, font);
    sfText_setPosition(text, new_pos);
    sfText_setString(text, name);
    sf_text_set_pixel_size(text, size);
    sfRenderWindow_drawText(window, text, NULL);
}

static void draw_line(sfRenderWindow *window, char *line, int dir, sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2i pos = {332 - 10, 756 - 20};
    sfVector2f size = {1544, 248};
    sfVector2f new_pos;

    if (dir != 0)
        pos.x = 64;
    new_pos = sfRenderWindow_mapPixelToCoords(window, pos,
        sfRenderWindow_getView(window));
    line = add_new_lines(line);
    sfText_setFont(text, font);
    sfText_setPosition(text, new_pos);
    sfText_setString(text, line);
    sf_text_set_pixel_size(text, size);
    sfRenderWindow_drawText(window, text, NULL);
}

static void display_line(sfRenderWindow *window, json_obj_t *obj, font_t **fonts)
{
    sfVector2f none = {0, 0};
    sfFont *font = find_font(get_str_by_name(obj, "font"), fonts);
    object_t *pic = create_object(get_str_by_name(obj, "image"), none, none);
    int direction = get_int_by_name(obj, "direction");

    draw_chatbox(window, direction);
    draw_pic(window, pic, direction);
    draw_name(window, get_str_by_name(obj, "name"), direction, font);
    draw_line(window, get_str_by_name(obj, "text"), direction, font);
    destroy_object(pic);
}

void display_dialogue(game_t *game, char *path, int *step, font_t **fonts)
{
    json_obj_t *json = create_json_object(path);
    json_obj_t *obj = get_obj_by_index(json, *step);

    if (game->ENTER == 2)
        *step += 1;
    if (obj != NULL)
        display_line(game->window->window, obj, fonts);
}
