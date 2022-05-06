/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** spawn_enemies.c
*/

#include "enemies.h"
#include "my.h"
#include "my_csfml_utils.h"
#include "my_game_struct.h"

enemy_node_t *spawn_ennemies(int nb, enemy_t *types, game_t *game)
{
    int len = 0;
    enemy_node_t *first = malloc(sizeof(enemy_node_t));
    enemy_node_t *actual = first;
    sfVector2i map_dim = {game->game->maps[get_current_map(game)]->width * 64,
        game->game->maps[get_current_map(game)]->height * 64};

    for (len = 0; types[len].type != -1; len++);
    for (int i = 0; i < nb; i++) {
        actual->enemy = types[rand() % len];
        actual->enemy.object = create_textured_object(
            actual->enemy.object->texture,
            VCF{rand() % map_dim.x, rand() % map_dim.y}, VCF{1, 1});
        if (i < nb - 1) {
            actual->next = malloc(sizeof(enemy_node_t));
            actual = actual->next;
        } else
            actual->next = NULL;
    }
    return first;
}
