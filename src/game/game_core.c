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
    free(game->keys);
    destroy_object(game->mouse);
    free(game->status);
}

item_t create_yellow_flower(item_t item, int number)
{
    item.stack_size = 255;
    item.armor_type = HEAD;
    item.quantity = number;
    item.armor_type = 1;
    item.type = FLOWER_YELLOW;
    item.obj = create_object("assets/img/select.png", VCF {0, 0}, VCF {4, 4});
    return (item);
}

int my_rpg(void)
{
    game_t *game = init_game_struct();
    competences_t competence = (competences_t) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 2, 0
        , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 , 0, 0 ,
        0 , 0, 0, 0, 0, 0 ,0 ,0 ,0, NULL};
    competence.sprites = setup_comp_sprites();
    game->items = create_items();
    game->items[10] = create_yellow_flower(game->items[10], 100);
    game->comp = malloc(sizeof(competences_t));
    game->comp = &competence;
    if (game == NULL)
        return 84;
    intro(game);
    menu(game);
    destroy_game(game);
    free_window_struct(game->window);
    return 0;
}
