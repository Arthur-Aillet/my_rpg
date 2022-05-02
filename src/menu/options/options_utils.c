/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** options_utils
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>

#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "main_menu.h"
#include "my_math.h"
#include "my_rpg.h"
#include "my_mouse.h"
#include "my_button.h"
#include "keyboard.h"
#include "my_csfml_utils.h"
#include "my.h"
#include "inventory_structures.h"

static void destroy_options_2(options_menu_t *option)
{
    destroy_slider(option->general);
    destroy_slider(option->sfx);
    destroy_slider(option->music);
    free(option);
}

void destroy_options(options_menu_t *option)
{
    destroy_object(option->back);
    destroy_button(option->display);
    destroy_button(option->volume);
    destroy_button(option->quit);
    sfText_destroy(option->screen_type_title);
    destroy_button(option->screen_type_right);
    destroy_button(option->screen_type_left);
    destroy_object(option->screen_type_background);
    destroy_button(option->screen_type_apply);
    sfText_destroy(option->screen_type_text);
    destroy_list(option->resolution);
    destroy_list(option->frame);
    sfText_destroy(option->vsync_title);
    destroy_check_box(option->vsync);
    sfText_destroy(option->general_title);
    sfText_destroy(option->sfx_title);
    sfText_destroy(option->music_title);
    destroy_options_2(option);
}
