/*
** EPITECH PROJECT, 2022
** my_rpg_main_2
** File description:
** init_pnj
*/

#include <stdlib.h>

#include "my.h"
#include "my_rpg.h"
#include "my_game_struct.h"
#include "player_animation.h"
#include "keyboard.h"

void destroy_pnjs(pnj_t **pnjs)
{
    for (int i = 0; pnjs[i] != NULL; i++) {
        free(pnjs[i]->name);
        destroy_object(pnjs[i]->portrait);
        destroy_object(pnjs[i]->objet);
        for (int j = 0; pnjs[j]->dialogues[j] != NULL; j++)
            free(pnjs[i]->dialogues[j]);
        free(pnjs[i]->dialogues);
        free(pnjs[i]->map_name);
    }
    free(pnjs);
}

pnj_t *create_pnj(json_obj_t *obj)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    json_obj_t *dialogues = dialogues;
    int nbr;

    pnj->objet = create_object(get_str_by_name(obj, "idle"),
        VCF{get_int_by_name(obj, "pos_x"),
        get_int_by_name(obj, "pos_y")}, VCF{1, 1});
    pnj->portrait = create_object(get_str_by_name(obj, "portrait"),
        VCF{0, 0}, VCF{1, 1});
    for (nbr = 0; get_str_by_index(dialogues, nbr)
        != NULL; nbr++);
    pnj->dialogues = malloc(sizeof(char *) * nbr);
    for (nbr = 0; get_str_by_index(dialogues, nbr) != NULL; nbr++) {
        pnj->dialogues[nbr] = my_strdup(get_str_by_index
            (dialogues, nbr));
    }
    sfSprite_setPosition(pnj->objet->sprite, VCF{get_int_by_name(obj, "pos_x"), get_int_by_name(obj, "pos_y")});
    pnj->map_name = my_strdup(get_str_by_name(obj, "map"));
    pnj->dialogues[nbr] = NULL;
    pnj->name = my_strdup(obj->name);
    pnj->size = get_int_by_name(obj, "size");
    free_json(dialogues, 1);
    return (pnj);
}

pnj_t **create_pnjs(void)
{
    json_obj_t *pnjs_json = create_json_object("config/pnj.json");
    json_obj_t *obj = get_obj_by_index(pnjs_json, 0);
    pnj_t **pnjs;
    int len;

    for (len = 0; obj != NULL; len++)
        obj = get_obj_by_index(pnjs_json, len);
    pnjs = malloc(sizeof(pnj_t *) * (len + 1));
    pnjs[len] = NULL;
    for (int i = 0; obj != NULL; i++) {
        obj = get_obj_by_index(pnjs_json, i);
        pnjs[i] = create_pnj(obj);
    }
/*     free_json(obj, 1); */
    free_json(pnjs_json, 1);
    return (pnjs);
}
