/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_WORLD_C
** File description:
** my_display_world
*/

#include "my_rpg.h"
#include "my.h"
#include "ui.h"

void setup_camera(game_t *game, int i)
{
    game->game->pos_cam = game->game->player->pos;
    if (game->game->pos_cam.x - game->game->cam_rect.width / 2 < 0)
        game->game->pos_cam.x = game->game->cam_rect.width / 2;
    if (game->game->pos_cam.y - game->game->cam_rect.height / 2 < 0)
        game->game->pos_cam.y = game->game->cam_rect.height / 2;
    if (game->game->pos_cam.x + game->game->cam_rect.width / 2 >
        game->game->maps[i]->width * 64)
        game->game->pos_cam.x = game->game->maps[i]->width * 64 -
            game->game->cam_rect.width / 2;
    if (game->game->pos_cam.y + game->game->cam_rect.height / 2 >
        game->game->maps[i]->height * 64)
        game->game->pos_cam.y = game->game->maps[i]->height * 64 -
            game->game->cam_rect.height / 2;
    sfView_setCenter(game->game->cam, game->game->pos_cam);
    sfRenderWindow_setView(game->window->window, game->game->cam);
}

void display_world(game_t *game)
{
    int i = get_current_map(game);
    sfVector2f vec = game->game->pos_cam;

    vec.x -= 960;
    vec.y -= 540;
    display_base(game, game->game->maps[i],
        0, game->game->maps[i]->height);
    display_player(game);
    display_obs(game, game->game->maps[i],
        (game->game->player->pos.y + 16) / 64 + 1, game->game->maps[i]->height);
    display_ui(game->window->window, game->game->player, vec);
    setup_camera(game, i);
}
