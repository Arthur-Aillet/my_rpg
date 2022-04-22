/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_csfml_utils
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/System.h>

#define VCF (sfVector2f)
#define VCU (sfVector2u)
#define VCI (sfVector2i)

typedef struct object_s {
    sfSprite *sprite;
    sfTexture *texture;
} object_t;

sfVector2f itofv2(sfVector2i vector);
sfVector2i ftoiv2(sfVector2f vector);
object_t *create_textured_object(sfTexture *img, sfVector2f pos, sfVector2f si);
object_t *create_object(char *name, sfVector2f pos, sfVector2f scale);
void sf_sprite_set_pixel_size(sfSprite *sprite, sfVector2f size);
void sf_text_set_pixel_size(sfText *text, sfVector2f size);
sfImage *create_blank_image(void);
void destroy_object(object_t *objet);
