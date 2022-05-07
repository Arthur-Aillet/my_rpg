/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** enemies_gestion.c
*/

#include "enemies.h"
#include "my.h"
#include "my_rpg.h"
#include "my_csfml_utils.h"
#include "my_game_struct.h"

void main_enemies(enemy_node_t *enemies, game_t *game)
{
    static char *map = NULL;
    maps_t *map_object = NULL;

    if (map == NULL || my_strcmp(game->game->current, map) != 0) {
        //free_enemies(game->game->enemies);
        map_object = game->game->maps[get_current_map(game)];
        if (map_object == NULL)
            return;
        map = game->game->current;
        game->game->enemies = spawn_ennemies(map_object->enemies,
            game->game->samples_enemies, game);
    }
    if (game->game->enemies == NULL)
        return;
    displace_enemies(enemies, game);
}
