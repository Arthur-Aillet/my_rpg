/*
** EPITECH PROJECT, 2022
** rpg - set competence st upper
** File description:
** sets the st of the upper competences
*/

#include "inventory_structures.h"

static competences_t set_competence_five(int comp, competences_t comps, int st)
{
    switch (comp) {
        case (29) : comps.c29 = st;
            break;
        case (30) : comps.c30 = st;
            break;
        case (31) : comps.c31 = st;
            break;
        case (32) : comps.c32 = st;
            break;
        case (33) : comps.c33 = st;
            break;
        case (34) : comps.c34 = st;
            break;
        case (35) : comps.c35 = st;
            break;
        default: comps = set_competence_six(comp, comps, st);
    }
    return (comps);
}
static competences_t set_competence_four(int comp, competences_t comps, int st)
{
    switch (comp) {
        case (22) : comps.c22 = st;
            break;
        case (23) : comps.c23 = st;
            break;
        case (24) : comps.c24 = st;
            break;
        case (25) : comps.c25 = st;
            break;
        case (26) : comps.c26 = st;
            break;
        case (27) : comps.c27 = st;
            break;
        case (28) : comps.c28 = st;
            break;
        default: comps = set_competence_five(comp, comps, st);
    }
    return (comps);
}
static competences_t set_competence_three(int comp, competences_t comps, int st)
{
    switch (comp) {
        case (15) : comps.c15 = st;
            break;
        case (16) : comps.c16 = st;
            break;
        case (17) : comps.c17 = st;
            break;
        case (18) : comps.c18 = st;
            break;
        case (19) : comps.c19 = st;
            break;
        case (20) : comps.c20 = st;
            break;
        case (21) : comps.c21 = st;
            break;
        default: comps = set_competence_four(comp, comps, st);
    }
    return (comps);
}
static competences_t set_competence_two(int comp, competences_t comps, int st)
{
    switch (comp) {
        case (8) : comps.c8 = st;
            break;
        case (9) : comps.c9 = st;
            break;
        case (10) : comps.c10 = st;
            break;
        case (11) : comps.c11 = st;
            break;
        case (12) : comps.c12 = st;
            break;
        case (13) : comps.c13 = st;
            break;
        case (14) : comps.c14 = st;
            break;
        default: comps = set_competence_three(comp, comps, st);
    }
    return (comps);
}

competences_t set_competence_state(int comp, competences_t comps, int st)
{
    switch (comp) {
        case (1) : comps.fireball = st;
            break;
        case (2) : comps.dodge_roll = st;
            break;
        case (3) : comps.c3 = st;
            break;
        case (4) : comps.c4 = st;
            break;
        case (5) : comps.c5 = st;
            break;
        case (6) : comps.c6 = st;
            break;
        case (7) : comps.c7 = st;
            break;
        default: comps = set_competence_two(comp, comps, st);
    }
    //  if (st == 2)
    //      comps.comp_points -= 1;
    return (comps);
}
