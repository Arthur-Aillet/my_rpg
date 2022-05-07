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

int enemy_is_collide(game_t *game, int xy, sfVector2f diff, sfVector2f enemypos)
{
    int i = -1;
    int j = 0;
    int map = get_current_map(game);
    int ret = 0;

    if (xy == 0)
        enemypos.x += diff.x;
    else
        enemypos.y += diff.y;
    while (game->game->maps[map]->maps[1][++i]) {
        j = -1;
        while (game->game->maps[map]->maps[1][i][++j])
            ret = ((int)((enemypos.x + 2) / 64) == j ||
                (int)((enemypos.x - 2) / 64) + 1 == j) &&
                game->game->maps[map]->maps[1][i][j] != '0' &&
                ((int)((enemypos.y + 32) / 64) == i ||
                (int)((enemypos.y - 2) / 64) + 1 == i)
                ? 1 : ret;
    }
    return ret;
}

sfVector2f keep_only_xy(sfVector2f vector, int xy)
{
    if (xy == 0)
        vector.y = 0;
    else
        vector.x = 0;
    return vector;
}

int determinate_enemy_direction(sfVector2f displacement)
{
    if (ABS(displacement.x) > ABS(displacement.y))
        return (displacement.x > 0) + (displacement.x < 0) * 3;
    else
        return (displacement.y < 0) * 2;
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
