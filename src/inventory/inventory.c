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
    #include "my_text.h"
    #include "particles.h"
    #include "dialogue.h"
    #include "ui.h"
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
        result[i].sprite = sfSprite_create();
        result[i].texture = sfTexture_create(1, 1);
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

item_t *menu(sfRenderWindow *window, item_t *items, competences_t *comp, char *keys)
{
    backgrounds_t backgrounds = setup_backgrounds(items, comp, window, keys);
    static int page = 0;
    events_t events = {window, items, &page, keys, comp};
    static void (*disp[3])(backgrounds_t) = {disp_inv, disp_map, disp_cmp};
    events_t (*evt[3])(events_t) = {evt_inv, evt_map, evt_cmp};
    particle_t *start = create_particle((sfVector2f) {0, 0}, 0, 0);
    font_t **fonts = font_create_array();
    ui_t health = (ui_t) {0, 1500};

    while (sfRenderWindow_isOpen(window)) {
        if (J == 2) {
            start = add_particle(start, (sfVector2f) {rand() % 1920, 0}, SNOW, 20);
            start = add_particle(start, (sfVector2f) {rand() % 1920, 0}, RAIN, 15);
            start = add_particle(start, (sfVector2f) {970, 540}, FIRE, 20);
            if (rand() % 100 == 0)
                for (int i = 0; i < 1000; i++)
                    start = add_particle(start, (sfVector2f) {485, 540}, DUST_CIRCLE, 15);
            start = add_particle(start, (sfVector2f) {1465, 540}, DUST_UP, -10);
            start = add_particle(start, (sfVector2f) {1465, 540}, DUST_UP_RIGHT, -10);
            start = add_particle(start, (sfVector2f) {1465, 540}, DUST_RIGHT, -10);
            start = add_particle(start, (sfVector2f) {1465, 540}, DUST_DOWN_RIGHT, -10);
            start = add_particle(start, (sfVector2f) {1465, 540}, FIRE_UP, 10);
            start = add_particle(start, (sfVector2f) {1465, 540}, FIRE_UP_RIGHT, 10);
            start = add_particle(start, (sfVector2f) {1465, 540}, FIRE_RIGHT, 10);
            start = add_particle(start, (sfVector2f) {1465, 540}, FIRE_DOWN_RIGHT, 10);
            start = add_particle(start, (sfVector2f) {970, 740}, SPARK, 10);
            start = add_particle(start, (sfVector2f) {200, 540}, ELECTRICITY, 15);
            start = add_particle(start, (sfVector2f) {1800, 540}, LEAF, 50);
        }
        disp[page](backgrounds);//
        events = evt[page](events);//
        update_particles(window, start);//
        if (P) {
            exterminate(start);
            return (items);
        }
        display_dialogue(window, "src/dialogue/example.json", keys, fonts);
        display_ui(window, health);
        //health.health = health.max_health;
        health.health += 1;
        if (health.health > health.max_health) health.health = 0;
        sfRenderWindow_display(window);//
    }
    return (items);
}
