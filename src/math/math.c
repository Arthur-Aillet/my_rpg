/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** math
*/

#include "my_math.h"
#include <math.h>
#include <stdbool.h>
#include <SFML/Graphics.h>

float dist_two_points(sfVector2f point1, sfVector2f point2)
{
    return (sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2)));
}

float orient_a_to_b(sfVector2f po1, sfVector2f po2)
{
    float distance_1 = dist_two_points(po1, (sfVector2f){po1.x, po2.y});
    float distance_2 = dist_two_points(po1, po2);
    float angle = distance_1 / distance_2;

    angle = RToD(asin(angle));
    if (po1.x > po2.x && po1.y > po2.y)
        angle += 180;
    if (po1.x > po2.x && !(po1.y > po2.y)) {
        angle += 180;
        angle *= -1;
    }
    if (!(po1.x > po2.x) && po1.y > po2.y)
        angle *= -1;
    return (angle);
}
