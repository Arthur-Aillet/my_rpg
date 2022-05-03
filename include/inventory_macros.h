/*
** EPITECH PROJECT, 2022
** rpg - inventory macros
** File description:
** here be abreviations
*/

#pragma once

#define NOTHING 0
#define SWORD 1
#define NB_SLOTS 65
#define SCALEX 1
#define SCALEY 1
#define HEAD 1
#define CHEST 2
#define LEGS 3
#define FEET 4
#define BIG(x, y) ((x < y) ? (y) : (x))
#define SMALL(x, y) ((x < y) ? (x) : (y))
#define BETWEEN(var, x, y) (SMALL(x, y) <= var && var <= BIG(x, y))
