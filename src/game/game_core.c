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
    destroy_pnjs(game->game->pnjs);
    free(game->keys);
    destroy_object(game->mouse);
    free(game->status);
}

item_t create_sword(item_t item, int number)
{
    item.stack_size = 255;
    item.armor_type = HEAD;
    item.quantity = number;
    item.armor_type = 0;
    item.type = SWORD;
    item.obj = create_object("assets/img/sword.png", VCF {0, 0}, VCF {4, 4});
    sf_sprite_set_pixel_size(item.obj->sprite, VCF {96, 96});
    return (item);
}

void test_function(game_t * game)
{
    for (int i = 0; i < 1000; i++)
        game->particles = add_particle(game->particles, game->game->player->pos, DUST_CIRCLE, 10);
}

int my_rpg(void)
{
    game_t *game = init_game_struct();
    competences_t competence = (competences_t) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 2
        , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        , 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 0};
    competence.sprites = setup_comp_sprites();
    game->items = create_items();
    game->items[10] = create_sword(game->items[10], 1);
    game->items[10].action = test_function;
    game->comp = malloc(sizeof(competences_t));
    competence.comp_points = 5;
    game->comp = &competence;
    if (game == NULL)
        return 84;
    intro(game);
    menu(game);
    destroy_game(game);
    free_window_struct(game->window);
    return 0;
}
