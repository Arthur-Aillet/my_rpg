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

static item_t create_yellow_flower(item_t item, int number)
{
    item.stack_size = 255;
    item.armor_type = HEAD;
    item.quantity = number;
    item.armor_type = 1;
    item.type = FLOWER_YELLOW;
    item.obj = create_object("assets/img/select.png", VCF {0, 0}, VCF {4, 4});
    return (item);
}

int my_rpg(int ac, char **av)
{
    game_t *game = init_game_struct();
    game->items = create_items();
    game->items[10] = create_yellow_flower(game->items[10], 100);
    game->comp = malloc(sizeof(competences_t));
    game->comp->dodge_roll = 0;
    game->comp->fireball = 0;

    if (game == NULL)
        return 84;
    menu(game);
    free_window_struct(game->window);
    return 0;
}
