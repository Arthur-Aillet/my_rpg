/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** volume
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>

#include "my_window_struct.h"
#include "my_text.h"
#include "my_sound.h"
#include "main_menu.h"
#include "my_math.h"
#include "my_rpg.h"
#include "my_mouse.h"
#include "my_button.h"
#include "keyboard.h"
#include "my_csfml_utils.h"
#include "my.h"
#include "inventory_structures.h"

void init_volume(game_t *game, options_menu_t *option)
{
    option->general_title = sfText_create();
    sfText_setFont(option->general_title, FONTG("Ancient.ttf"));
    sfText_setString(option->general_title, "General:");
    sfText_setCharacterSize(option->general_title, 60);
    sfText_setPosition(option->general_title, VCF{1920 / 2 - 249, 260});
    option->sfx_title = sfText_create();
    sfText_setFont(option->sfx_title, FONTG("Ancient.ttf"));
    sfText_setString(option->sfx_title, "SFX:");
    sfText_setCharacterSize(option->sfx_title, 60);
    sfText_setPosition(option->sfx_title, VCF{1920 / 2 - 249, 540 + 120});
    option->music_title = sfText_create();
    sfText_setFont(option->music_title, FONTG("Ancient.ttf"));
    sfText_setString(option->music_title, "Music:");
    sfText_setCharacterSize(option->music_title, 60);
    sfText_setPosition(option->music_title, VCF{1920 / 2 - 249, 540 - 80});
    option->sfx = create_slider(VCF{1920 / 2 - 249, 540 + 200});
    option->music = create_slider(VCF{1920 / 2 - 249, 540});
    option->general = create_slider(VCF{1920 / 2 - 249, 540 - 200});
}

void silder_sfx_manager(game_t *game, options_menu_t *option)
{
    sfVector2f mouse_pos = get_global_mouse_pos(game->window->window);
    sfFloatRect rect = sfSprite_getGlobalBounds(option->sfx->back->sprite);
    static bool need_switch = false;

    if (MOUSE_HOVER == true && game->LCLICK)
        need_switch = true;
    if (!game->LCLICK)
        need_switch = false;
    if (need_switch == true) {
        game->sfx_volume = ((mouse_pos.x - rect.left) * 100 / (rect.width - 5));
        game->sfx_volume = MAX(0, game->sfx_volume);
        game->sfx_volume = MIN(100, game->sfx_volume);
        sfSprite_setPosition(option->sfx->slider->sprite, VCF{rect.left + rect.width / 100 * game->sfx_volume, sfSprite_getPosition(option->sfx->slider->sprite).y});
        sfSprite_setScale(option->sfx->front->sprite, VCF{game->sfx_volume / 100 * 2, 2});
        for (int i = 0; game->sounds[i] != NULL; i++)
            sfSound_setVolume(game->sounds[i]->sound, game->sfx_volume);
    }
}

void silder_music_manager(game_t *game, options_menu_t *option)
{
    sfVector2f mouse_pos = get_global_mouse_pos(game->window->window);
    sfFloatRect rect = sfSprite_getGlobalBounds(option->music->back->sprite);
    static bool need_switch = false;

    if (MOUSE_HOVER == true && game->LCLICK)
        need_switch = true;
    if (!game->LCLICK)
        need_switch = false;
    if (need_switch == true) {
        game->music_volume = ((mouse_pos.x - rect.left) * 100 / (rect.width - 5));
        game->music_volume = MAX(0, game->music_volume);
        game->music_volume = MIN(100, game->music_volume);
        sfSprite_setPosition(option->music->slider->sprite, VCF{rect.left + rect.width / 100 * game->music_volume, sfSprite_getPosition(option->music->slider->sprite).y});
        sfSprite_setScale(option->music->front->sprite, VCF{game->music_volume / 100 * 2, 2});
        for (int i = 0; game->musics[i] != NULL; i++) {
            if (game->musics[i]->music != NULL)
                sfMusic_setVolume(game->musics[i]->music, game->music_volume);
        }
    }
}

void silder_general_manager(game_t *game, options_menu_t *option)
{
    sfVector2f mouse_pos = get_global_mouse_pos(game->window->window);
    sfFloatRect rect = sfSprite_getGlobalBounds(option->general->back->sprite);
    static bool need_switch = false;

    if (MOUSE_HOVER == true && game->LCLICK)
        need_switch = true;
    if (!game->LCLICK)
        need_switch = false;
    if (need_switch == true) {
        game->general_volume = ((mouse_pos.x - rect.left) * 100 / (rect.width - 5));
        game->general_volume = MAX(0, game->general_volume);
        game->general_volume = MIN(100, game->general_volume);
        sfSprite_setPosition(option->general->slider->sprite, VCF{rect.left + rect.width / 100 * game->general_volume, sfSprite_getPosition(option->general->slider->sprite).y});
        sfSprite_setScale(option->general->front->sprite, VCF{game->general_volume / 100 * 2, 2});
        sfListener_setGlobalVolume(game->general_volume);
    }
}
