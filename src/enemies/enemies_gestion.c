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

int determinate_enemy_direction(sfVector2f displacement)
{
    if (ABS(displacement.x) > ABS(displacement.y))
        return (displacement.x > 0) + (displacement.x < 0) * 3;
    else
        return (displacement.y < 0) * 2;
}

sfVector2f keep_only_xy(sfVector2f vector, int xy)
{
    if (xy == 0)
        vector.y = 0;
    else
        vector.x = 0;
    return vector;
}

void main_enemies(enemy_node_t *enemies, game_t *game)
{
    static char *map = NULL;
    maps_t *map_object = NULL;

    if (map == NULL || my_strcmp(game->game->current, map) != 0) {
        free_enemies(game->game->enemies);
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
