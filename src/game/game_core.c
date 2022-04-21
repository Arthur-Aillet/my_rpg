/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** game_core
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>

#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "my_rpg.h"
#include "my_mouse.h"
#include "my_button.h"
#include "keyboard.h"
#include "my_csfml_utils.h"
#include "main_menu.h"
#include "inventory_structures.h"

int my_rpg(int ac, char **av)
{
    game_t *game = init_game_struct();
    item_t *items = create_items();
    items[10] = create_yellow_flower(items[10], 100);
    competences_t *comp = malloc(sizeof(competences_t));
    comp->dodge_roll = 0;
    comp->fireball = 0;

    if (game == NULL)
        return 84;
    create_windows(game->window);
    menu(game, items, comp);
    free_window_struct(game->window);
    return 0;
}
