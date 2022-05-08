/*
** EPITECH PROJECT, 2022
** my_rpg_main_2
** File description:
** quest
*/

#include "my_math.h"
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

static char *quest_string_manager(game_t *game, char *string)
{
    char *char_slime;

    string = malloc(sizeof(char) * 29);
    string = my_strcpy(string, "Quest: kill 10 slime\n\t\t\t");
    char_slime = malloc(sizeof(char) * 2);
    char_slime[0] = game->game->player->slime_killed + 48;
    char_slime[1] = '\0';
    string = my_strcat(string, char_slime);
    string = my_strcat(string, "/10");
    free(char_slime);
    return string;
}

void update_quest(game_t *game)
{
    char *string = NULL;
    pnj_t *oldmen;

    if (game->game->player->slime_killed < 10) {
        sfText_setPosition(game->game->quest, VCF{game->game->pos_cam.x + 670,
            game->game->pos_cam.y - 515});
        string = quest_string_manager(game, string);
        sfText_setString(game->game->quest, string);
        sfRenderWindow_drawText(game->window->window, game->game->quest, NULL);
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
        reward = create_speed_potion_l(reward, 10);
        pickup_item(reward, game->items);
    }
}
