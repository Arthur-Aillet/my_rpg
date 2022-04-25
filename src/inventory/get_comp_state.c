/*
** EPITECH PROJECT, 2022
** rpg - get comp state
** File description:
** gets te states of the competences
*/

#include "inventory_structures.h"

static int getting_fifth_part(int comp, competences_t competences)
{
    switch (comp) {
        case (65) : return (competences.c65);
        case (66) : return (competences.c66);
        case (67) : return (competences.c67);
    }
    return (0);
}

static int getting_fourth_part(int comp, competences_t competences)
{
    switch (comp) {
        case (49) : return (competences.c49);
        case (50) : return (competences.c50);
        case (51) : return (competences.c51);
        case (52) : return (competences.c52);
        case (53) : return (competences.c53);
        case (54) : return (competences.c54);
        case (55) : return (competences.c55);
        case (56) : return (competences.c56);
        case (57) : return (competences.c57);
        case (58) : return (competences.c58);
        case (59) : return (competences.c59);
        case (60) : return (competences.c60);
        case (61) : return (competences.c61);
        case (62) : return (competences.c62);
        case (63) : return (competences.c63);
        case (64) : return (competences.c64);
        default : return (getting_fifth_part(comp, competences));
    }
    return (0);
}

static int getting_third_part(int comp, competences_t competences)
{
    switch (comp) {
        case (33) : return (competences.c33);
        case (34) : return (competences.c34);
        case (35) : return (competences.c35);
        case (36) : return (competences.c36);
        case (37) : return (competences.c37);
        case (38) : return (competences.c38);
        case (39) : return (competences.c39);
        case (40) : return (competences.c40);
        case (41) : return (competences.c41);
        case (42) : return (competences.c42);
        case (43) : return (competences.c43);
        case (44) : return (competences.c44);
        case (45) : return (competences.c45);
        case (46) : return (competences.c46);
        case (47) : return (competences.c47);
        case (48) : return (competences.c48);
        default : return (getting_fourth_part(comp, competences));
    }
    return (0);
}

static int getting_second_part(int comp, competences_t competences)
{
    switch (comp) {
        case (17) : return (competences.c17);
        case (18) : return (competences.c18);
        case (19) : return (competences.c19);
        case (20) : return (competences.c20);
        case (21) : return (competences.c21);
        case (22) : return (competences.c22);
        case (23) : return (competences.c23);
        case (24) : return (competences.c24);
        case (25) : return (competences.c25);
        case (26) : return (competences.c26);
        case (27) : return (competences.c27);
        case (28) : return (competences.c28);
        case (29) : return (competences.c29);
        case (30) : return (competences.c30);
        case (31) : return (competences.c31);
        case (32) : return (competences.c32);
        default : return (getting_third_part(comp, competences));
    }
    return (0);
}

int get_competence_state(int comp, competences_t competences)
{
    switch (comp) {
        case (1) : return (competences.fireball);
        case (2) : return (competences.dodge_roll);
        case (3) : return (competences.c3);
        case (4) : return (competences.c4);
        case (5) : return (competences.c5);
        case (6) : return (competences.c6);
        case (7) : return (competences.c7);
        case (8) : return (competences.c8);
        case (9) : return (competences.c9);
        case (10) : return (competences.c10);
        case (11) : return (competences.c11);
        case (12) : return (competences.c12);
        case (13) : return (competences.c13);
        case (14) : return (competences.c14);
        case (15) : return (competences.c15);
        case (16) : return (competences.c16);
        default : return (getting_second_part(comp, competences));
    }
    return (0);
}
