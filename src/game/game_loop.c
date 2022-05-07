/*
** EPITECH PROJECT, 2022
** GAME_LOOP_C
** File description:
** game_loop
*/

#include "my_rpg.h"
#include "keyboard.h"
#include "enemies.h"
#include "my_game_struct.h"
#include "pnjs.h"
#include "my.h"
#include "inventory_prototypes.h"
#include "object_creation.h"
#include "keyboard.h"
#include "particles.h"
#include "main_menu.h"

static void poll_event_keys(game_t *game)
{
    game->keys = get_keyboard_input(game->keys, game->window->window);
    if (game->ESC == 2)
        game->status->end_game = pause_menu(game);
    if (game->TAB == 2 || game->I == 2)
        game = inventory(game);
}

void update_player_status(game_t *game)
{
    if (game->game->player->exp > game->game->player->max_exp) {
        game->game->player->exp = 0;
        game->game->player->max_exp += game->game->player->max_exp / 3;
        game->comp->comp_points += 1;
    }
}

void update_game_status(game_t *game)
{
    update_player_status(game);
    if (MUSICG("our_home.flac") == NULL || MUSICG("death_mountains.flac")
        == NULL || MUSICG("mysterious_chasm.flac") == NULL)
        return;
    if (my_strcmp(game->game->current,"field") == 0 && sfMusic_getStatus(MUSICG("death_mountains.flac")) != 2) {
        sfMusic_play(MUSICG("death_mountains.flac"));
        if (sfMusic_getStatus(MUSICG("mysterious_chasm.flac")) == 2)
            sfMusic_stop(MUSICG("mysterious_chasm.flac"));
        if (sfMusic_getStatus(MUSICG("our_home.flac")) == 2)
            sfMusic_stop(MUSICG("our_home.flac"));
    }
    if (my_strcmp(game->game->current,"town") == 0 && sfMusic_getStatus(MUSICG("mysterious_chasm.flac")) != 2) {
        sfMusic_play(MUSICG("mysterious_chasm.flac"));
        if (sfMusic_getStatus(MUSICG("our_home.flac")) == 2)
            sfMusic_stop(MUSICG("our_home.flac"));
        if (sfMusic_getStatus(MUSICG("death_mountains.flac")) == 2)
            sfMusic_stop(MUSICG("death_mountains.flac"));
    }
    if ((my_strcmp(game->game->current,"house") == 0 || my_strcmp(game->game->current,"garden") == 0) && sfMusic_getStatus(MUSICG("our_home.flac")) != 2) {
        sfMusic_play(MUSICG("our_home.flac"));
        if (sfMusic_getStatus(MUSICG("mysterious_chasm.flac")) == 2)
            sfMusic_stop(MUSICG("mysterious_chasm.flac"));
        if (sfMusic_getStatus(MUSICG("death_mountains.flac")) == 2)
            sfMusic_stop(MUSICG("death_mountains.flac"));
    }
}

void player_move_cinematic(game_t *game, int horizontal, int veritcal)
{
    float spd = 0.4;
    int count = game->game->player->move_spd;

    while (count--)
        game->game->player->pos = VCF{game->game->player->pos.x + spd *
            horizontal, game->game->player->pos.y + spd * veritcal};
}

void cinematic(game_t *game)
{
    object_t *bandeau = create_object("assets/img/bandeau.png", VCF{0, 0}, VCF{60, 50});
    int clicked = 0;
    int e_click = 0;
    pnj_t *women = find_pnj("women", game);
    pnj_t *oldmen = find_pnj("oldmen", game);

    game->ENTER = 0;
    game->game->player->pos.x = 876;
    game->game->player->pos.y = 440;
    oldmen->next_dialogue = my_strdup("config/mission1.json");
    women->next_dialogue = my_strdup("config/greetings_women.json");
    while (game->status->end_game == 0 && sfRenderWindow_isOpen
            (game->window->window) && game->ESC != 2) {
        sfRenderWindow_clear(game->window->window, sfBlack);
        set_correct_window_size(game->window);
        main_enemies(game->game->enemies, game);
        update_game_status(game);
        if (game->ENTER == 2 && e_click == 1) {
            clicked += 1;
            if (clicked >= 4)
                game->status->end_game = 1;
        }
        if (game->game->player->pos.x <= 1292) {
            if (game->ENTER == 2)
                game->game->player->pos.x = 1292;
            display_world_cinematic(game, 1, 0, bandeau);
            player_move_cinematic(game, 1, 0);
        } else {
            if (e_click == 1 && game->E == 2)
                game->E = 0;
            if (game->E == 2)
                e_click = 1;
            display_world_cinematic(game, 0, 0, bandeau);
            player_move_cinematic(game, 0, 0);
        }
        sfSprite_setPosition(bandeau->sprite, VCF{game->game->pos_cam.x - 1920 / 2, game->game->pos_cam.y - 1080 / 2});
        game->keys = get_keyboard_input(game->keys, game->window->window);
        sfRenderWindow_display(game->window->window);
    }
    game->status->end_game = 0;
    destroy_object(bandeau);
    game->game->player->pos.x = 1292;
}

void update_quest(game_t *game)
{
    char *string;
    char *char_slime;
    pnj_t *oldmen;

    if (game->game->player->slime_killed < 10) {
        string = malloc(sizeof(char) * 28);
        string = my_strcpy(string, "Quest: kill 10 slime\n\t\t\t");
        char_slime = malloc(sizeof(char) * 2);
        char_slime[0] = game->game->player->slime_killed + 48;
        char_slime[1] = '\0';
        string = my_strcat(string, char_slime);
        string = my_strcat(string, "/10");
        sfText_setPosition(game->game->quest, VCF{game->game->pos_cam.x + 670,
            game->game->pos_cam.y - 515});
        sfText_setString(game->game->quest, string);
        sfRenderWindow_drawText(game->window->window, game->game->quest, NULL);
        free(char_slime);
        free(string);
    } else {
        oldmen = find_pnj("oldmen", game);
        if (oldmen == NULL)
            return;
        free(oldmen->next_dialogue);
        oldmen->next_dialogue = my_strdup("config/mission1_end.json");
    }
}

void give_reward(game_t *game)
{
    static bool given = false;
    item_t reward;
    pnj_t *oldmen = find_pnj("oldmen", game);

    if (given == false && oldmen != NULL && game->game->player->slime_killed
        >= 10 && game->E == 2 && dist_two_points(sfSprite_getPosition(
        oldmen->objet->sprite), game->game->player->pos) <= 200) {
        given = true;
        reward = create_cuirass(reward, 1);
        pickup_item(reward, game->items);
    }
}

int game_loop(game_t *game)
{
    static int switched = 0;
    static int seen = 0;
    pnj_t *oldmen = find_pnj("oldmen", game);

    transition(game, 2);
    game->game->samples_enemies = create_enemies_array();
    if (game->game->samples_enemies == NULL)
        return 84;
    if (seen == 0) {
        cinematic(game);
        seen = 1;
    }
    while (game->status->end_game == 0 && sfRenderWindow_isOpen
            (game->window->window)) {
        if (my_strcmp(game->game->current, "house") != 0 && switched == 0) {
            if (oldmen != NULL) {
                free(oldmen->map_name);
                sfSprite_setPosition(oldmen->objet->sprite, VCF{775, 600});
                oldmen->map_name = my_strdup("town");
                oldmen->next_dialogue = my_strdup("config/greetings.json");
            }
            switched = 1;
        }
        sfRenderWindow_clear(game->window->window, sfBlack);
        set_correct_window_size(game->window);
        main_enemies(game->game->enemies, game);
        display_world(game);
        update_quest(game);
        update_game_status(game);
        player_actions(game);
        poll_event_keys(game);
        give_reward(game);
        sfRenderWindow_display(game->window->window);
    }
    game->game->pos_cam.x = 960;
    game->game->pos_cam.y = 540;
    sfView_setCenter(game->game->cam, game->game->pos_cam);
    sfRenderWindow_setView(game->window->window, game->game->cam);
    game->status->end_game = 0;
    return 0;
}
