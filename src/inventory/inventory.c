/*
** EPITECH PROJECT, 2021
** menu - main loop
** File description:
** setup and main loop
*/

#include "keyboard.h"
#include "particles.h"
#include "pause_menu.h"
#include "csfml_libs.h"
#include "my_button.h"
#include "mouse.h"
#include "inventory_prototypes.h"
#include "my_game_struct.h"
#include "my_csfml_utils.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

item_t *create_items(void)
{
    item_t *result = malloc(sizeof (item_t) * NB_SLOTS);
    for (int i = 0; i < NB_SLOTS; i++) {
        result[i].quantity = 0;
        result[i].type = NOTHING;
        result[i].obj = create_object("assets/img/fine_dust.png",
            VCF {0, 0}, VCF {0, 0});
        result[i].stack_size = 1;
        result[i].armor_type = 5;
        result[i].action = NULL;
    }
    return (result);
}

int count_item(item_t *items, int type)
{
    int count = 0;

    for (int i = NB_SLOTS - 1; i >= 0; i--)
        if (items[i].type == type)
            count += items[i].quantity;
    return (count);
}

static void free_inventory(backgrounds_t background, events_t events)
{
    for (int i = 0; i < 3; i++)
        destroy_object(background.pages[i]);
    sfText_destroy(background.text.text);
    destroy_button(events.button);
}

game_t *update_stats(game_t *game)
{
    game->game->player->max_health = 1000;
    game->game->player->max_stamina = 1000;
    game->game->player->move_spd = 8;
    for (int i = 1; i < 68; i++) {
        if (BETWEEN(i, 30, 38) && get_competence_state
            (i, *game->comp) == 2 && i != 33)
            game->game->player->move_spd += 1;
        if (i > 38 && get_competence_state(i, *game->comp) == 2) {
            game->game->player->max_health += 100;
            game->game->player->health += 100;
        }
        if (i < 30 && get_competence_state(i, *game->comp) == 2) {
            game->game->player->max_stamina += 100;
            game->game->player->stamina += 100;
        }
        if (i == 33 && get_competence_state(i, *game->comp) == 2)
            game->game->player->dash = 0;
    }
    return (game);
}

game_t *inventory(game_t *game)
{
    backgrounds_t backgrounds = setup_backgrounds(game);
    static int page = 0;
    sfView *view = sfRenderWindow_getView(game->window->window);
    events_t events = setup_events(game, &page);
    static void (*disp[3])(backgrounds_t) = {disp_inv, disp_map, disp_cmp};
    events_t (*evt[3])(events_t) = {evt_inv, evt_map, evt_cmp};

    sfView_setCenter(view, VCF {970, 540});
    sfRenderWindow_clear(game->window->window, sfBlack);
    sfRenderWindow_setView(game->window->window, view);
    while (game->E != 2) {
        disp[page](backgrounds);
        events = evt[page](events);
        sfRenderWindow_display(game->window->window);
    }
    game = update_stats(game);
    game->E = 0;
    free_inventory(backgrounds, events);
    return (game);
}
