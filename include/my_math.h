/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_math
*/

#ifndef MY_MATH_H_
    #define MY_MATH_H_

    #include <stdbool.h>
    #include <SFML/Graphics.h>

    #include "my_csfml_utils.h"

    #define DToR(Angle) (Angle * M_PI / 180.0)
    #define RToD(Angle) (Angle * 180.0 / M_PI)
    #define ATOV(angle) cos(angle * 2 * M_PI / 360), sin(angle * 2 * M_PI / 360)
    #define MOUSE_HOVER sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)
    #define INVERT_VCF(vector) VCF{1 / vector.x, 1 / vector.y}

float orient_a_to_b(sfVector2f po1, sfVector2f po2);
float dist_two_points(sfVector2f point1, sfVector2f point2);

#endif /* !MY_MATH_H_ */
