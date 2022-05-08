/*
** EPITECH PROJECT, 2022
** rpg - menu destroy
** File description:
** destroys the menu
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "my_window_struct.h"
#include "my_text.h"
#include "main_menu.h"
#include "my_button.h"
#include "my_csfml_utils.h"

void destroy_menu(main_menu_t *menu)
{
    destroy_button(menu->quit);
    destroy_button(menu->new_game);
    destroy_button(menu->continue_game);
    destroy_button(menu->options);
    destroy_object(menu->back);
    sfClock_destroy(menu->clock);
    destroy_object(menu->title);
    exterminate(menu->particle);
}
