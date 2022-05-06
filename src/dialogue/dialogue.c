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

static void draw_pic(game_t *game, object_t *pic, int direction)
{
    sfVector2f pos = {game->game->pos_cam.x - 914, 124 + game->game->pos_cam.y};
    sfVector2f size = {240, 376};

    if (direction != 0)
        pos.x += 1593;
    sfSprite_setPosition(pic->sprite, pos);
    sf_sprite_set_pixel_size(pic->sprite, size);
    sfRenderWindow_drawSprite(game->window->window, pic->sprite, NULL);
}

static void draw_name(game_t *game, char *name, int dir, sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f pos = {game->game->pos_cam.x - 642, 134 + game->game->pos_cam.y};
    sfVector2f size = {200, 44};

    if (dir != 0)
        pos.x += 1098;
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setString(text, name);
    sf_text_set_pixel_size(text, size);
    sfRenderWindow_drawText(game->window->window, text, NULL);
}

static void draw_line(game_t *game, char *line, int dir, sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f pos = {game->game->pos_cam.x - 628, 196 + game->game->pos_cam.y};
    sfVector2f size = {1544, 248};

    if (dir != 0)
        pos.x -= 278;
    line = add_new_lines(line);
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setString(text, line);
    sf_text_set_pixel_size(text, size);
    sfRenderWindow_drawText(game->window->window, text, NULL);
}

static void display_line(game_t *game, json_obj_t *obj, font_t **fonts)
{
    sfVector2f none = {0, 0};
    sfFont *font = find_font(get_str_by_name(obj, "font"), fonts);
    object_t *pic = create_object(get_str_by_name(obj, "image"), none, none);
    int direction = get_int_by_name(obj, "direction");

    draw_chatbox(game, direction);
    draw_pic(game, pic, direction);
    draw_name(game, get_str_by_name(obj, "name"), direction, font);
    draw_line(game, get_str_by_name(obj, "text"), direction, font);
    destroy_object(pic);
}

void display_dialogue(game_t *game, char *path, int *step, font_t **fonts)
{
    json_obj_t *json = create_json_object(path);
    json_obj_t *obj = get_obj_by_index(json, *step);

    if (game->ENTER == 2)
        *step += 1;
    if (obj != NULL)
        display_line(game, obj, fonts);
    else
        *step = -1;
}
