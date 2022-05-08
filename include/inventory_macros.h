/*
** EPITECH PROJECT, 2022
** rpg - inventory macros
** File description:
** here be abreviations
*/

#pragma once

#define NOTHING 0
#define SWORD 1
#define HEAL_POTION_S 2
#define HEAL_POTION_M 3
#define HEAL_POTION_L 4
#define HEAL_POTION_R 5
#define STAMINA_POTION_S 6
#define STAMINA_POTION_M 7
#define STAMINA_POTION_L 8
#define STAMINA_POTION_R 9
#define SPEED_POTION_S 10
#define SPEED_POTION_M 11
#define SPEED_POTION_L 12
#define HELMET 13
#define CUIRASS 14
#define BREECHES 15
#define SABATON 16
#define GEL 17
#define MOLOTOF 18
#define NB_SLOTS 65
#define HEAD 1
#define CHEST 2
#define LEGS 3
#define FEET 4
#define BIG(x, y) ((x < y) ? (y) : (x))
#define SMALL(x, y) ((x < y) ? (x) : (y))
#define BETWEEN(var, x, y) (SMALL(x, y) <= var && var <= BIG(x, y))
