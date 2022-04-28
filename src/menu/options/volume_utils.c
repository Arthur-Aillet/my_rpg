/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** volume_utils
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

static void set_correct_sound_volume(game_t *game)
{
    for (int i = 0; game->sounds[i] != NULL; i++)
        if (game->sounds[i]->sound != NULL)
            sfSound_setVolume(game->sounds[i]->sound, game->sfx_volume);
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
        sfSprite_setPosition(option->sfx->slider->sprite,
            VCF{rect.left + rect.width / 100 * game->sfx_volume,
            sfSprite_getPosition(option->sfx->slider->sprite).y});
        sfSprite_setScale(option->sfx->front->sprite,
            VCF{game->sfx_volume / 100 * 2, 2});
        set_correct_sound_volume(game);
    }
}

static void set_correct_music_volume(game_t *game)
{
    for (int i = 0; game->musics[i] != NULL; i++)
        if (game->musics[i]->music != NULL)
            sfMusic_setVolume(game->musics[i]->music, game->music_volume);
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
        game->music_volume = ((mouse_pos.x - rect.left) * 100 /
            (rect.width - 5));
        game->music_volume = MAX(0, game->music_volume);
        game->music_volume = MIN(100, game->music_volume);
        sfSprite_setPosition(option->music->slider->sprite,
            VCF{rect.left + rect.width / 100 * game->music_volume,
            sfSprite_getPosition(option->music->slider->sprite).y});
        sfSprite_setScale(option->music->front->sprite,
            VCF{game->music_volume / 100 * 2, 2});
        set_correct_music_volume(game);
    }
}
