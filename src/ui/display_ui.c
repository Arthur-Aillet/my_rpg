/*
** EPITECH PROJECT, 2022
** rpg - display ui
** File description:
** displays the ui
*/

#include "csfml_libs.h"
#include "my_csfml_utils.h"
#include "ui.h"
#include <stdlib.h>
#include "my_game_struct.h"
#include "inventory_prototypes.h"

static object_t **get_more_parts(object_t **result)
{
    sfVector2f pos_exp = {130, 94};
    sfVector2f pos_bar = {342, 960};
    sfVector2f select_pos = {334, 952};
    sfVector2f scaleexp = {0.5, 0.5};
    sfVector2f scalebar = {4, 4};

    result[7] = create_object("assets/img/ui/exp_bg.png", pos_exp, scaleexp);
    result[8] = create_object("assets/img/ui/exp.png", pos_exp, scaleexp);
    result[9] = create_object("assets/img/ui/hotbar.png", pos_bar, scalebar);
    result[10] = create_object("assets/img/select.png", select_pos, scalebar);
    return (result);
}

static object_t **get_parts(void)
{
    static object_t **result = NULL;
    sfVector2f pos_circle = {0, 0};
    sfVector2f pos_health = {130, 38};
    sfVector2f pos_stamina = {130, 66};
    sfVector2f scale = {0.5, 0.5};

    if (result != NULL)
        return (result);
    result = malloc(sizeof(object_t) * 11);
    result[0] = create_object("assets/img/ui/pp_bg.png", pos_circle, scale);
    result[1] = create_object("assets/img/ui/pp_circle.png", pos_circle, scale);
    result[2] = create_object("assets/img/player/neutral.png"
        , VCF{49, 25}, scale);
    result[3] = create_object("assets/img/ui/health_bg.png", pos_health, scale);
    result[4] = create_object("assets/img/ui/health.png", pos_health, scale);
    result[5] = create_object("assets/img/ui/stamina_bg.png"
        , pos_stamina, scale);
    result[6] = create_object("assets/img/ui/stamina.png", pos_stamina, scale);
    result = get_more_parts(result);
    return (result);
}

static void display_circle(sfRenderWindow *window, object_t **parts)
{
    sf_sprite_set_pixel_size(parts[2]->sprite, VCF {144 * 0.5, 229 * 0.5});
    sfRenderWindow_drawSprite(window, parts[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, parts[2]->sprite, NULL);
    sfRenderWindow_drawSprite(window, parts[1]->sprite, NULL);
}

void display_hotbar_items(game_t *game)
{
    sfVector2f pos = {-606 + game->game->pos_cam.x, 433 + game->
        game->pos_cam.y};
    for (int i = 51; i <= 60; i++) {
        sfSprite_setPosition(game->items[i].obj->sprite, pos);
        pos.x += 124;
        if (game->items[i].type == 0 || game->items[i].quantity == 0){
            game->items[i].quantity = 0;
            game->items[i].type = 0;
            game->items[i].action = NULL;
        }
        if (game->items[i].quantity > 0) {
            sfRenderWindow_drawSprite(game->window->window
                , game->items[i].obj->sprite, NULL);
        }
    }
}

void display_ui(sfRenderWindow *window, player_t *player, sfVector2f pos)
{
    object_t **parts = get_parts();
    sfVector2f former_pos = sfSprite_getPosition(parts[0]->sprite);

    if (former_pos.x != pos.x || former_pos.y != pos.y) {
        former_pos = VCF {pos.x - former_pos.x, pos.y - former_pos.y};
        for (int i = 0 ; i < 11; i++)
            sfSprite_move(parts[i]->sprite, former_pos);
        former_pos = pos;
    }
    display_health(window, player->health, player->max_health, parts);
    display_stamina(window, player->stamina, player->max_stamina, parts);
    display_exp(window, player->exp, player->max_exp, parts);
    display_circle(window, parts);
    display_hotbar(window, player, parts);
}
