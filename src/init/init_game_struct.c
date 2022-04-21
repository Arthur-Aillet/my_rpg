/*
** EPITECH PROJECT, 2022
** MY_INIT_GAME_STRUCT_C
** File description:
** my_init_game_struct
*/

#include <stdlib.h>

#include "my_csfml_utils.h"
#include "my_game_struct.h"
#include "my_rpg.h"

game_t *init_game_struct(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return NULL;
    game->mouse = create_object("assets/img/cursors.png", VCF{0, 0}, VCF{1.4, 1.4});
    game->fonts = font_create_array();
    game->sounds = sounds_create_array();
    game->window = generate_default_window();
    game->status = init_game_status();
    game->keys = init_keys();
    game->game = init_in_game_struct();
    if (game->window == NULL || game->status == NULL || game->keys == NULL)
        return NULL;
    return game;
}
