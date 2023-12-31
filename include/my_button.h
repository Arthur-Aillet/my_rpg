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

#include "my_csfml_utils.h"
#include "my_text.h"
#include "my_game_struct.h"

typedef struct button_s {
    sfVector2f scale_hover;
    sfVector2f scale_click;
    sfVector2f original_scale;
    sfVector2f original_text_scale;
    sfVector2f text_offset;
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

typedef struct slider_s{
    object_t *back;
    object_t *front;
    object_t *slider;
} slider_t;

typedef struct check_s{
    button_t *on;
    button_t *off;
    bool status;
} check_t;

typedef struct list_s{
    button_t *up;
    button_t *down;
    button_t **element;
    bool value;
} list_t;

void destroy_list(list_t *list);
list_t *create_list(sfVector2f pos, game_t *game, char *text);
void update_list(list_t *list, game_t *game);
void slider_init(slider_t *slider, float volume);
void destroy_slider(slider_t *slider);
slider_t *create_slider(sfVector2f pos);
check_t *create_check(sfVector2f pos, game_t *game);
void update_checkbox_vsync(check_t *check, game_t *game);
void destroy_check_box(check_t *check);
void update_checkbox(check_t *check, game_t *game);
bool is_pressed(button_t *bouton, sfRenderWindow *window, char *keys);
button_t *button_create(sfVector2f size, sfVector2f position, bool display_tex);
void button_setup_texture_file(button_t *bouton, sfIntRect size, char *file);
void button_setup_texture(button_t *btn, sfIntRect size, sfTexture *texture);
void button_setup_text_file(button_t *bouton, char *text, char *font, int size);
void button_setup_text(button_t *bouton, char *text, sfFont *font, int size);
void button_setup_sounds_file(button_t *but, char *click, char *hover, int vol);
void button_center_text(button_t *bouton);
void button_update_state(sfVector2f mouse_pos, button_t *but, char *keys);
void display_button(sfRenderWindow *window, button_t *but);
void update_button(sfRenderWindow *window, button_t *but, char *keys);
void destroy_button(button_t *bouton);
void button_setup_sounds(button_t *but, sfSound *click, sfSound *hover, int vo);
void button_setup_offset(button_t *b, sfVector2f h, sfVector2f c, sfVector2f t);
void update_button_no_display(sfRenderWindow *window, button_t *but, char *key);
void button_setup_correct_texture(button_t *bouton, sfIntRect size);
void sf_text_set_size(sfText *text, sfVector2f size);
void display_slider(slider_t *slider, game_t *game);
void hover_but(button_t *but);
void leave_but(button_t *but);
void button_play_sound(sfVector2f mo, button_t *but, char *keys, sfFloatRect r);
void click_but(button_t *but);
