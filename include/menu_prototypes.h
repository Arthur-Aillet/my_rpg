/*
** EPITECH PROJECT, 2022
** rpg - menu prototypes
** File description:
** here be descriptions
*/

#include "inventory_structures.h"

#ifndef MENU_PROTOTYPES_H_
    #define MENU_PROTOTYPES_H_

int get_competence(sfVector2f pos);
int get_slot(sfVector2f pos);
int is_adjacent_comp(int comp, int test);

sfVector2f get_comp_pos(int comp);
sfVector2f get_slot_pos(int slot, sfRenderWindow *window);

struct backgrounds setup_backgrounds(struct item *, struct competences*, sfRenderWindow *, char *);

struct item *add_items(int origin, int dest, struct item *items);
struct item *level_items(int dest, int origin, int max, struct item *items);
struct item *split_item(int origin, int dest, struct item *items, int number);
struct item *swap_items(int origin, int dest, struct item *items);


void disp_cmp(struct backgrounds bgs);
void draw_competences(sfRenderWindow *window, struct competences *comp);
void disp_inv(struct backgrounds bgs);
void disp_map(struct backgrounds bgs);
void draw_items(sfRenderWindow *window, struct item *items, struct txtobject text);

struct events evt_cmp(struct events events);
struct events evt_inv(struct events events);
struct events evt_map(struct events events);

#endif /* !MENU_PROTOTYPES_H_ */
