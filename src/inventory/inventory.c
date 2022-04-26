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
#include "mouse.h"
#include "inventory_prototypes.h"
#include "my_game_struct.h"
    #include "my_text.h"
    #include "particles.h"
    #include "dialogue.h"
    #include "ui.h"
    #include "player_animation.h"
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
        result[i].obj = create_object("nothing",VCF {0, 0}, VCF {0, 0});
        result[i].stack_size = 1;
        result[i].armor_type = 5;
    }
    return (result);
}

void free_txtobject(txtobject_t object)
{
    sfText_destroy(object.text);
    sfFont_destroy(object.font);
}

int count_item(item_t *items, int type)
{
    int count = 0;

    for (int i = NB_SLOTS - 1; i >= 0; i--)
        if (items[i].type == type)
            count += items[i].quantity;
    return (count);
}

game_t *inventory(game_t *game)
{
    backgrounds_t backgrounds = setup_backgrounds(game);//
    static int page = 0;//
    events_t events = {game->window->window, game->items, &page, game->keys, button_create(VCF {1, 1}, VCF {200, 20}, 1), game->comp};//
    button_setup_texture_file(events.button, (sfIntRect) {0, 0, 263, 79}, "assets/img/button.jpg");
    button_setup_text(events.button, "test", FONTG("Ancient.ttf"), 20);
    button_setup_sounds(events.button, SOUNDG("hover.ogg"), SOUNDG("click.ogg"), 20);
    button_setup_offset(events.button, VCF {2, 2}, VCF {1, 1});
    static void (*disp[3])(backgrounds_t) = {disp_inv, disp_map, disp_cmp};
    events_t (*evt[3])(events_t) = {evt_inv, evt_map, evt_cmp};//
    particle_t *start = create_particle((sfVector2f) {0, 0}, 0, 0);
    font_t **fonts = font_create_array();
    sfVector2f vec = {0, 0};
    player_t player = {0, 1000, 0, 500, 0, 250, 0, VCF {0, 0}, NULL, NULL, "\0", 0};
    int animation = 0;

    while (sfRenderWindow_isOpen(game->window->window)) {//
        if (game->J) {   start = add_particle(start, (sfVector2f) {rand() % 1920, 0}, SNOW, 20);    start = add_particle(start, (sfVector2f) {rand() % 1920, 0}, RAIN, 15); start = add_particle(start, (sfVector2f) {970, 500}, FIRE, 20);  if (rand() % 100 == 0)    for (int i = 0; i < 1000; i++)  start = add_particle(start, (sfVector2f) {485, 540}, DUST_CIRCLE, 15);    start = add_particle(start, (sfVector2f) {1465, 540}, DUST_UP, -10);    start = add_particle(start, (sfVector2f) {1465, 540}, DUST_UP_RIGHT, -10);  start = add_particle(start, (sfVector2f) {1465, 540}, DUST_RIGHT, -10);   start = add_particle(start, (sfVector2f) {1465, 540}, DUST_DOWN_RIGHT, -10);   start = add_particle(start, (sfVector2f) {1465, 540}, FIRE_UP, 10);    start = add_particle(start, (sfVector2f) {1465, 540}, FIRE_UP_RIGHT, 10);   start = add_particle(start, (sfVector2f) {1465, 540}, FIRE_RIGHT, 10); start = add_particle(start, (sfVector2f) {1465, 540}, FIRE_DOWN_RIGHT, 10);  start = add_particle(start, (sfVector2f) {970, 740}, SPARK, 10);  start = add_particle(start, (sfVector2f) {200, 540}, ELECTRICITY, 15);    start = add_particle(start, (sfVector2f) {1800, 540}, LEAF, 50);    start = add_particle(start, VCF {900, 540}, LIGHT_DUST, 10); start = add_particle(start, VCF {1920, rand() % 1080}, MAGIC_VIBE, 10);}
        disp[page](backgrounds);//
        events = evt[page](events);//
        update_particles(game->window->window, start);
        if (game->ESC == 2) {//
            exterminate(start);
            return (game);//
        }
        if (game->K) display_dialogue(game->window->window, "src/dialogue/example.json", game->keys, fonts);
        player.exp += 1;    player.stamina += 1;    player.health += 1; if (player.exp > player.max_exp) player.exp = 0;    if (player.stamina > player.max_stamina) player.stamina = 0;    if (player.health > player.max_health) player.health = 0;
        if (game->G) display_ui(game->window->window, &player, vec);
        sfRenderWindow_display(game->window->window);//
    }//
    return (game);//
}
