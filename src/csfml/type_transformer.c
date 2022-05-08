/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** type_transformer
*/

#include <SFML/Graphics.h>

sfVector2f itofv2(sfVector2i vector)
{
    sfVector2f result;

    result.x = vector.x;
    result.y = vector.y;
    return (result);
}

sfVector2i ftoiv2(sfVector2f vector)
{
    sfVector2i result;

    result.x = vector.x;
    result.y = vector.y;
    return (result);
}
