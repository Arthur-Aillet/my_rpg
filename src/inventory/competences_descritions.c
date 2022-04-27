/*
** EPITECH PROJECT, 2022
** rpg - competences descriprions
** File description:
** writing the description of the competences
*/

#include "inventory_structures.h"
#include "inventory_prototypes.h"
#include "my_rpg.h"
#include "my_csfml_utils.h"
#include "json.h"

void display_description(sfRenderWindow *window, json_obj_t *json, int i,
    sfText *text)
{
    sfText_setOrigin(text, VCF {0, 0});
    sfText_setPosition(text, VCF {96, 60});
    sfText_setString(text, get_str_by_name(get_obj_by_index(json, i)
        , "description"));
    sfRenderWindow_drawText(window, text, NULL);
}

void draw_descriptions(sfRenderWindow *window, competences_t *comp, sfText *txt)
{
    int state = 0;
    json_obj_t *json = NULL;

    if (json == NULL)
        json = create_json_object("src/inventory/comp_desc.json");
    for (int i = 1; i < 68; i++) {
        state = get_competence_state(i, *comp);
        if (state == 1)
            display_description(window, json, i, txt);
    }
}
