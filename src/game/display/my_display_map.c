/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_MAP_C
** File description:
** my_display_map
*/

#include "my_rpg.h"
#include "my.h"

static void print_tile_map(game_t *game, char **map, sfVector2f vec, int p)
{
    int i = get_current_map(game);
    sfIntRect rect = {0, 0,
        game->game->maps[i]->def, game->game->maps[i]->def};

    if (map[(int)vec.y][(int)vec.x] == '1')
        rect.left = game->game->maps[i]->def;
    if (map[(int)vec.y][(int)vec.x] == '0' && p == 0)
        return;
    sfSprite_setTextureRect(game->game->maps[i]->sp_ts , rect);
    vec.x *= 64;
    vec.y *= 64;
    sfSprite_setPosition(game->game->maps[i]->sp_ts, vec);
    sfSprite_setScale(game->game->maps[i]->sp_ts,
        VCF {64 / game->game->maps[i]->def, 64 / game->game->maps[i]->def});
    sfRenderWindow_drawSprite(game->window->window, game->game->maps[i]->sp_ts,
        NULL);
}

void display_base(game_t *game, maps_t *maps, int begin, int end)
{
    sfVector2f vec = {0, begin};

    while (maps->base[(int)vec.y] && vec.y < end) {
        vec.x = 0;
        while (maps->base[(int)vec.y][(int)vec.x]) {
            print_tile_map(game, maps->base, vec, 1);
            print_tile_map(game, maps->obs, vec, 0);
            vec.x++;
        }
        vec.y++;
    }
}

void display_obs(game_t *game, maps_t *maps, int begin, int end)
{
    sfVector2f vec = {0, begin};

    while (maps->base[(int)vec.y] && vec.y < end) {
        vec.x = 0;
        while (maps->base[(int)vec.y][(int)vec.x]) {
            print_tile_map(game, maps->obs, vec, 0);
            vec.x++;
        }
        vec.y++;
    }
}
