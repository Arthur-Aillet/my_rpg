/*
** EPITECH PROJECT, 2021
** menu - main loop
** File description:
** setup and main loop
*/

#include "keyboard.h"
#include "pause_menu.h"
#include "csfml_libs.h"
#include "mouse.h"
#include "inventory.h"
#include "menu_prototypes.h"
#include "particles_structures.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct object setup_mouse(void);
sfVector2f itofv2(sfVector2i vector);
void update_particles(sfRenderWindow *window, struct particle *start);
struct particle *create_particle(sfVector2f pos, int type);

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.height = height;
    video_mode.width = width;
    video_mode.bitsPerPixel = 16;
    window = sfRenderWindow_create(video_mode, "my_rpg", sfDefaultStyle, NULL);
    return (window);
}

void free_object(struct object object)
{
    sfSprite_destroy(object.sprite);
    sfTexture_destroy(object.texture);
}

void free_txtobject(struct txtobject object)
{
    sfText_destroy(object.text);
    sfFont_destroy(object.font);
}

void free_menu( struct backgrounds bgs, struct object mouse)
{
    free_object(mouse);
    for (int i = 0; i < 2; i++)
        free_object(bgs.pages[i]);
    free(bgs.pages);
    free_txtobject(bgs.text);
}

struct item *pickup_item(struct item new, struct item *items)
{
    int free_spot = 0;

    for (; items[free_spot].type != 0; free_spot++);
    for (int i = 0; i < NB_SLOTS; i++) {
        while (items[i].type == new.type &&
            items[i].quantity < items[i].stack_size && new.quantity > 0) {
            items[i].quantity += 1;
            new.quantity -= 1;
        }
    }
    sfTexture_destroy(items[free_spot].texture);
    sfSprite_destroy(items[free_spot].sprite);
    items[free_spot] = new;
    return (items);
}

int count_item(struct item *items, int type)
{
    int count = 0;

    for (int i = NB_SLOTS - 1; i >= 0; i--)
        if (items[i].type == type)
            count += items[i].quantity;
    return (count);
}

struct item *consume(struct item *items, int type, int quantity)
{
    int nb_items = count_item(items, type);
    int j = 0;
    if (quantity > nb_items)
        return (items);
    while (nb_items > 0) {
        if (items[j].type != type)
            j += 1;
        while (items[j].type == type && items[j].quantity > 0) {
            nb_items -= 1;
            items[j].quantity -= 1;
        }
        if (items[j].quantity == 0) {
            items[j].type = 0;
            items[j].armor_type = 5;
            items[j].stack_size = 1;
            sfSprite_destroy(items[j].sprite);
            sfTexture_destroy(items[j].texture);
        }
    }
    return (items);
}

struct item *pickup_items(struct item *items, char *keys, int *pressed, int slot)
{
    if (items[slot].type != 0) {
        switch ((LCLICK == 2) * 4 + (RCLICK == 2) * 2 + (LSHIFT == 1)) {
            case (2) : split_item(slot, 0, items, items[slot].quantity / 2);
                break;
            case (3) : level_items(0, slot, 1, items);
                break;
            case (4) : swap_items(slot, 0, items);
                break;
            case (5) : level_items(0, slot, items[slot].quantity - 1, items);
                break;
            default : return (items);
        }
        *pressed = slot;
    }
    return (items);
}

struct item *equip(int pressed, int slot, struct item *items)
{
    if (items[0].armor_type == slot - 60 || items[0].armor_type == 5) {
        return (swap_items(slot, 0, items));
    }
    return (swap_items(pressed, 0, items));
}

struct item *drop_items(struct item *items, int pressed, int slot)
{
    int ptype = (items[pressed].type == items[0].type) * 4;
    if (items[0].type == 0)
        return (items);
    if (slot > 60)
        return (equip(pressed, slot, items));
    switch (ptype + (items[slot].type == items[0].type) * 2 + (slot == 0)) {
    case (0) : swap_items(slot, 0, items);
        break;
    case (1) : swap_items(pressed, 0, items);
        break;
    case (2) : add_items(0, slot, items);
        break;
    case (3) : swap_items(pressed, 0, items);
        break;
    case (4) : swap_items(0, slot, items);
        break;
    case (5) : add_items(0, pressed, items);
        break;
    case (6) : add_items(0, slot, items);
        break;
    case (7) : add_items(0, pressed, items);
    }
    if (items[slot].quantity > items[slot].stack_size && items[slot].type != 0)
            level_items(pressed, slot, items[slot].stack_size, items);
    return (items);
}

void resize_window(sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    static sfVector2u lastsize = {1920, 1080};

    if (size.y != lastsize.y) {
        size.x = size.y * 16 / 9;
        sfRenderWindow_setSize(window, size);
        lastsize = size;
    }
    if (size.x != lastsize.x) {
        size.y = size.x / 16 * 9;
        sfRenderWindow_setSize(window, size);
        lastsize = size;
    }
    sfRenderWindow_setSize(window, lastsize);
}

struct particle *add_particle(struct particle *first, sfVector2f pos, int type)
{
    struct particle *new = create_particle(pos, type);

    new->next = first;
    return (new);
}

struct item *menu(sfRenderWindow *window, struct item *items, struct competences comp, char *keys)
{
    struct object mouse = setup_mouse();
    struct backgrounds backgrounds = setup_backgrounds(items, &comp, window, keys);
    static int page = 0;
    struct events events = {window, items, &page, keys, &comp};
    static void (*disp[3])(struct backgrounds) = {disp_inv, disp_map, disp_cmp};
    struct events (*evt[3])(struct events) = {evt_inv, evt_map, evt_cmp};
    struct particle *start = create_particle((sfVector2f) {0, 0}, 0);

    while (sfRenderWindow_isOpen(window)) {
        start = add_particle(start, (sfVector2f) {rand() % 1920, 0}, 0);
        start = add_particle(start, (sfVector2f) {rand() % 1920, 0}, 1);
        start = add_particle(start, (sfVector2f) {970, 540}, 2);
        disp[page](backgrounds);
        events = evt[page](events);
        draw_mouse(window, mouse.sprite);
        update_particles(window, start);
        sfRenderWindow_display(window);
    }
    free_menu(backgrounds, mouse);
    return (items);
}
