/*
** EPITECH PROJECT, 2022
** rpg - set competences state down
** File description:
** stet the downmost competeces's states
*/

#include "inventory_structures.h"

static competences_t set_competence_ten(int comp, competences_t comps, int st)
{
    switch (comp) {
        case (64) : comps.c64 = st;
            break;
        case (65) : comps.c65 = st;
            break;
        case (66) : comps.c66 = st;
            break;
        case (67) : comps.c67 = st;
            break;
    }
    return (comps);
}

static competences_t set_competence_nine(int comp, competences_t comps, int st)
{
    switch (comp) {
        case (57) : comps.c57 = st;
            break;
        case (58) : comps.c58 = st;
            break;
        case (59) : comps.c59 = st;
            break;
        case (60) : comps.c60 = st;
            break;
        case (61) : comps.c61 = st;
            break;
        case (62) : comps.c62 = st;
            break;
        case (63) : comps.c63 = st;
            break;
        default: comps = set_competence_ten(comp, comps, st);
    }
    return (comps);
}

static competences_t set_competence_eight(int comp, competences_t comps, int st)
{
    switch (comp) {
        case (50) : comps.c50 = st;
            break;
        case (51) : comps.c51 = st;
            break;
        case (52) : comps.c52 = st;
            break;
        case (53) : comps.c53 = st;
            break;
        case (54) : comps.c54 = st;
            break;
        case (55) : comps.c55 = st;
            break;
        case (56) : comps.c56 = st;
            break;
        default: comps = set_competence_nine(comp, comps, st);
    }
    return (comps);
}

static competences_t set_competence_seven(int comp, competences_t comps, int st)
{
    switch (comp) {
        case (43) : comps.c43 = st;
            break;
        case (44) : comps.c44 = st;
            break;
        case (45) : comps.c45 = st;
            break;
        case (46) : comps.c46 = st;
            break;
        case (47) : comps.c47 = st;
            break;
        case (48) : comps.c48 = st;
            break;
        case (49) : comps.c49 = st;
            break;
        default: comps = set_competence_eight(comp, comps, st);
    }
    return (comps);
}

competences_t set_competence_six(int comp, competences_t comps, int st)
{
    switch (comp) {
        case (36) : comps.c36 = st;
            break;
        case (37) : comps.c37 = st;
            break;
        case (38) : comps.c38 = st;
            break;
        case (39) : comps.c39 = st;
            break;
        case (40) : comps.c40 = st;
            break;
        case (41) : comps.c41 = st;
            break;
        case (42) : comps.c42 = st;
            break;
        default: comps = set_competence_seven(comp, comps, st);
    }
    return (comps);
}
