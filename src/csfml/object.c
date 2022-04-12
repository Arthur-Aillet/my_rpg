/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** object
*/

#include "my_csfml_utils.h"

#include <SFML/Graphics.h>
#include <stdlib.h>

void create_purple_parts(unsigned char *pixels)
{
    for (int x = 0; x != 16; x++) {
        for (int y = 0; y != 16; y++) {
            pixels[32 * 4 * x + y * 4] = 255;
            pixels[32 * 4 * x + y * 4 + 1] = 0;
            pixels[32 * 4 * x + y * 4 + 2] = 255;
            pixels[32 * 4 * x + y * 4 + 3] = 255;
            pixels[32 * 4 * (x + 16) + (y + 16) * 4] = 255;
            pixels[32 * 4 * (x + 16) + (y + 16) * 4 + 1] = 0;
            pixels[32 * 4 * (x + 16) + (y + 16) * 4 + 2] = 255;
            pixels[32 * 4 * (x + 16) + (y + 16) * 4 + 3] = 255;
        }
    }
}

sfImage *create_blank_image(void)
{
    unsigned char *pixels = malloc(sizeof(unsigned char) * (32 * 32 * 4));
    sfImage *image;

    for (int i = 0; i != (32 * 32 * 4); i += 4) {
        pixels[i] = 0;
        pixels[i + 1] = 0;
        pixels[i + 2] = 0;
        pixels[i + 3] = 255;
    }
    create_purple_parts(pixels);
    image = sfImage_createFromPixels(32, 32, pixels);
    free(pixels);
    return (image);
}

object *create_object(char *name, sfVector2f pos, sfVector2f scale)
{
    object *obj = malloc(sizeof(object));
    sfImage *image;

    obj->sprite = sfSprite_create();
    if (obj->sprite == NULL)
        return (NULL);
    obj->texture = sfTexture_createFromFile(name, NULL);
    if (obj->texture == NULL) {
        image = create_blank_image();
        obj->texture = sfTexture_createFromImage(image, NULL);
        sfImage_destroy(image);
    }
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setScale(obj->sprite, scale);
    sfSprite_setPosition(obj->sprite, pos);
    return (obj);
}

object *create_textured_object(sfTexture *img, sfVector2f pos, sfVector2f scale)
{
    object *objet = malloc(sizeof(object));
    sfFloatRect rect;
    sfImage *image;

    objet->sprite = sfSprite_create();
    objet->texture = img;
    if (objet->texture == NULL) {
        image = create_blank_image();
        objet->texture = sfTexture_createFromImage(image, NULL);
        sfImage_destroy(image);
    }
    sfSprite_setTexture(objet->sprite, objet->texture, sfFalse);
    rect = sfSprite_getGlobalBounds(objet->sprite);
    sfSprite_setOrigin(objet->sprite,
        (sfVector2f){rect.width / 2, rect.height / 2});
    sfSprite_setScale(objet->sprite, scale);
    sfSprite_setPosition(objet->sprite, pos);
    return (objet);
}

void destroy_object(object *objet)
{
    sfTexture_destroy(objet->texture);
    sfSprite_destroy(objet->sprite);
}
