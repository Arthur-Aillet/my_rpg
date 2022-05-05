/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_MAP_C
** File description:
** my_display_map
*/

#include "my_rpg.h"
#include "my.h"

static void print_tile_map(game_t *game, maps_t *m, sfVector2f v, map_option_t opt)
{
    sfIntRect rect = {0, 0, m->def, m->def};

    rect.top = opt.layer * m->def;
    rect.left = (m->maps[opt.map][(int)v.y][(int)v.x] - '0') * m->def;
    if (rect.left == 0 && opt.space == 0)
        return;
    if (opt.space == 0)
        rect.left -= 1 * m->def;
    sfSprite_setTextureRect(m->sp_ts, rect);
    v.x *= 64;
    v.y *= 64;
    sfSprite_setPosition(m->sp_ts, v);
    sfSprite_setScale(m->sp_ts, VCF {64 / m->def, 64 / m->def});
    sfRenderWindow_drawSprite(game->window->window, m->sp_ts, NULL);
}

void display_map(game_t *game, int map, int layer, int space)
{
    sfVector2f vec = {0, 0};
    map_option_t opt = {space, layer, map};
    char **current_map = game->game->maps[get_current_map(game)]->maps[map];

    while (current_map[(int)vec.y]) {
        vec.x = 0;
        while (current_map[(int)vec.y][(int)vec.x]) {
            print_tile_map(game, game->game->maps[get_current_map(game)], vec, opt);
            vec.x++;
        }
        vec.y++;
    }
}
