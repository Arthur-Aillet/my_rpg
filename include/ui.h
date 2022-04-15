/*
** EPITECH PROJECT, 2022
** rpg - ui
** File description:
** user interface
*/

#include "csfml_libs.h"
#include "my_csfml_utils.h"

#ifndef UI_H_
    #define UI_H_

typedef struct ui_s {
    float health;
    float max_health;
} ui_t;

void display_health(sfRenderWindow *window, float current, float max, object_t **parts);
void display_ui(sfRenderWindow *window, ui_t ui);

#endif /* !UI_H_ */
