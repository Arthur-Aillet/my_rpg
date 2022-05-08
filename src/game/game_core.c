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
#include "my_game_struct.h"
#include "main_menu.h"
#include "pnjs.h"
#include "inventory_structures.h"
#include "inventory_prototypes.h"
#include "object_creation.h"

void free_sounds(game_t *game)
{
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
}

void destroy_game(game_t *game)
{
    if (game->fonts != NULL)
        for (int i = 0; game->fonts[i] != NULL; i++) {
            sfFont_destroy(game->fonts[i]->font);
            free(game->fonts[i]->name);
        }
    free(game->fonts);
    free_sounds(game);
    destroy_pnjs(game->game->pnjs);
    free(game->keys);
    destroy_object(game->mouse);
    free(game->status);
    sfText_destroy(game->game->quest);
}

void my_rpg(void)
{
    game_t *game = init_game_struct();
    competences_t competence = (competences_t) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2
        , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 0};
    competence.sprites = setup_comp_sprites();
    game->items = create_items();
    game->items[51] = create_sword(game->items[51], 1);
    game->comp = malloc(sizeof(competences_t));
    competence.comp_points = 0;
    game->comp = &competence;
    intro(game);
    menu(game);
    destroy_game(game);
    free_window_struct(game->window);
}
