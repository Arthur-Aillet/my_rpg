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

static void spawn_one_enemy(enemy_node_t *act, game_t *game, enemy_t *types, int len)
{
    sfVector2i map_dim = {game->game->maps[get_current_map(game)]->width * 64,
        game->game->maps[get_current_map(game)]->height * 64};
    sfVector2f temp_pos = {rand() % map_dim.x, rand() % map_dim.y};

    act->enemy = types[rand() % len];
    while (enemy_is_collide(game, 0, VCF{0, 0}, temp_pos))
        temp_pos = VCF{rand() % map_dim.x, rand() % map_dim.y};
    act->enemy.object = create_textured_object(
        sfTexture_copy(act->enemy.object->texture),
        VCF{rand() % map_dim.x, rand() % map_dim.y},
        VCF{act->enemy.scale, act->enemy.scale});
}

enemy_node_t *spawn_ennemies(int nb, enemy_t *types, game_t *game)
{
    int len = 0;
    enemy_node_t *first = malloc(sizeof(enemy_node_t));
    enemy_node_t *actual = first;

    if (nb == 0) {
        free(first);
        return NULL;
    }
    for (len = 0; types[len].type != -1; len++);
    for (int i = 0; i < nb; i++) {
        spawn_one_enemy(actual, game, types, len);
        if (i < nb - 1) {
            actual->next = malloc(sizeof(enemy_node_t));
            actual = actual->next;
        } else
            actual->next = NULL;
    }
    return first;
}
