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

static object_t **get_parts(void)
{
    static object_t **result = NULL;
    sfVector2f pos_circle = {0, 0};
    sfVector2f pos_health = {130, 38};
    sfVector2f pos_stamina = {130, 66};
    sfVector2f pos_exp = {130, 94};
    sfVector2f scale = {0.5, 0.5};

    if (result != NULL)
        return (result);
    result = malloc(sizeof(object_t) * 9);
    result[0] = create_object("assets/img/ui/pp_bg.png", pos_circle, scale);
    result[1] = create_object("assets/img/ui/pp_circle.png", pos_circle, scale);
    result[2] = create_object("assets/img/bap_open.png", VCF {30, 30}, scale);
    result[3] = create_object("assets/img/ui/health_bg.png", pos_health, scale);
    result[4] = create_object("assets/img/ui/health.png", pos_health, scale);
    result[5] = create_object("assets/img/ui/stamina_bg.png", pos_stamina, scale);
    result[6] = create_object("assets/img/ui/stamina.png", pos_stamina, scale);
    result[7] = create_object("assets/img/ui/exp_bg.png", pos_exp, scale);
    result[8] = create_object("assets/img/ui/exp.png", pos_exp, scale);
    return (result);
}

static void display_circle(sfRenderWindow *window, object_t **parts)
{
    sf_sprite_set_pixel_size(parts[2]->sprite, VCF {100, 100});
    sfRenderWindow_drawSprite(window, parts[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, parts[2]->sprite, NULL);
    sfRenderWindow_drawSprite(window, parts[1]->sprite, NULL);
}

void display_ui(sfRenderWindow *window, player_t *player)
{
    static object_t **parts = NULL;
    parts = get_parts();
    display_health(window, player->health, player->max_health, parts);
    display_stamina(window, player->stamina, player->max_stamina, parts);
    display_exp(window, player->exp, player->max_exp, parts);
    display_circle(window, parts);
}
