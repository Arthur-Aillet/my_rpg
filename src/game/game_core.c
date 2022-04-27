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

void destroy_game(game_t *game)
{
    if (game->fonts != NULL)
        for (int i = 0; game->fonts[i] != NULL; i++) {
            sfFont_destroy(game->fonts[i]->font);
            free(game->fonts[i]->name);
        }
    free(game->fonts);
    if (game->sounds != NULL)
        for (int i = 0; game->sounds[i] != NULL; i++) {
            sfSound_destroy(game->sounds[i]->sound);
            sfSoundBuffer_destroy(game->sounds[i]->buffer);
            free(game->sounds[i]->name);
        }
    free(game->sounds);
    if (game->musics != NULL)
        for (int i = 0; game->musics[i] != NULL; i++) {
            sfMusic_destroy(game->musics[i]->music);
            free(game->musics[i]->name);
        }
    free(game->musics);
    free(game->keys);
    destroy_object(game->mouse);
    free(game->status);
}

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
    menu(game, items, comp);
    destroy_game(game);
    free_window_struct(game->window);
    return 0;
}
