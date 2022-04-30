/*
** EPITECH PROJECT, 2022
** my_rpg_main_2
** File description:
** init_pnj
*/

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
    }
    free(pnjs);
}

void create_pnj(json_obj_t *obj)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    json_obj_t *dialogues = dialogues;
    int nbr_of_dialogues;

    pnj->objet = create_object(get_str_by_name(obj, "idle"),
        VCF{get_int_by_name(obj, "pos_x"),
        get_int_by_name(obj, "pos_y")}, VCF{1, 1});
    pnj->portrait = create_object(get_str_by_name(obj, "portrait"),
        VCF{0, 0}, VCF{1, 1});
    for (nbr_of_dialogues = 0; get_str_by_index(dialogues, nbr_of_dialogues)
        != NULL; nbr_of_dialogues++);
    pnj->dialogues = malloc(sizeof(char *) * nbr_of_dialogues);
    for (nbr_of_dialogues = 0; get_str_by_index(dialogues, nbr_of_dialogues)
        != NULL; nbr_of_dialogues++) {
        pnj->dialogues[nbr_of_dialogues] = my_strdup(get_str_by_index
            (dialogues, nbr_of_dialogues));
    }
    pnj->dialogues[nbr_of_dialogues] = NULL;
    pnj->name = my_strdup(obj->name);
    pnj->size = get_int_by_name(obj, "size");
    free_json(dialogues, 1);
}

void create_pnjs(in_game_t *game)
{
    json_obj_t *pnjs = create_json_object("config/pnj.json");
    json_obj_t *obj = get_obj_by_index(json, 0);
    int len = 0;

    while (obj != NULL) {
        len += 1;
        obj = get_obj_by_index(json, len);
        free_json(obj, 1);
    }
    game->pnjs = malloc(sizeof(pnj_t *) * (len + 1));
    game->pnjs[len] = NULL;
    obj = get_obj_by_index(json, 0);
    for (int i = 0; obj != NULL; i++)
        game->pnjs[i] = create_pnj(get_obj_by_index(json, i));
    free_json(pnjs);
}
