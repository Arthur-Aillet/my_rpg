/*
** EPITECH PROJECT, 2022
** MY_DISPLAY_WORLD_C
** File description:
** my_display_world
*/

#include "my_rpg.h"
#include "enemies.h"
#include "my.h"
#include "pnjs.h"
#include "ui.h"
#include "particles.h"
#include "player_animation.h"
#include "enemies.h"

#include <math.h>

static void setup_camera(game_t *game, int i)
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
    if (game->game->player->hurt > 0)
        sfView_zoom(game->game->cam, 0.98);
    if (game->game->player->hurt == 0)
        sfView_setSize(game->game->cam, VCF {1920, 1080});
    sfView_setCenter(game->game->cam, game->game->pos_cam);
    sfRenderWindow_setView(game->window->window, game->game->cam);
}

static void weather(game_t *game)
{
    static sfClock *clock = NULL;
    static int time = 0;

    if (clock == NULL)
        clock = sfClock_create();
    if (TIME(clock, 180) &&
        sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 1) {
        game->game->weather = rand() % 3;
        time = 60;
    }
    if (time != 0 && game->game->weather != 2) {
        for (int i = rand() % time / 3; i > 0; i--) {
            game->particles = add_particle(game->particles
                , VCF {game->game->pos_cam.x + rand () % 3000 - 1500
                , game->game->pos_cam.y + rand() % 2000 - 1000}
                , game->game->weather, 15);
        }
        if (TIME(clock, 1))
            time -= 1;
    }
}

void display_world_cinematic(game_t *game, int ho, int ve, object_t *bandeau)
{
    int i = get_current_map(game);
    sfVector2f vec = game->game->pos_cam;

    vec.x -= 960;
    vec.y -= 540;
    display_map(game, 0, 0, 1);
    display_map(game, 1, 1, 0);
    display_player_cinematic(game, ho, ve);
    display_pnjs(game);
    display_enemies(game, game->game->enemies);
    update_particles(game->window->window, game->particles);
    display_map(game, 2, 2, 0);
    display_ui(game->window->window, game->game->player, vec);
    display_hotbar_items(game);
    sfRenderWindow_drawSprite(game->window->window, bandeau->sprite, NULL);
    display_dialogues(game);
    setup_camera(game, i);
    weather(game);
}

void display_world(game_t *game)
{
    int i = get_current_map(game);
    sfVector2f vec = game->game->pos_cam;

    vec.x -= 960;
    vec.y -= 540;
    display_map(game, 0, 0, 1);
    display_map(game, 1, 1, 0);
    display_pnjs(game);
    if (game->game->in_dialogue == false)
        display_player(game);
    else
        PLACE_PLAYER(IDLE + game->game->player->side + ISDASH * 4);
    display_enemies(game, game->game->enemies);
    update_particles(game->window->window, game->particles);
    display_map(game, 2, 2, 0);
    display_ui(game->window->window, game->game->player, vec);
    display_hotbar_items(game);
    display_dialogues(game);
    setup_camera(game, i);
    weather(game);
}
