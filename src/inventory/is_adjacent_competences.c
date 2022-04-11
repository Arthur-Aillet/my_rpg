/*
** EPITECH PROJECT, 2022
** rpg - is adjacent competences
** File description:
** tells you if the competence is nex to that
*/

static int is_same_line(int src, int test, int mod)
{
    int type = 1;
    int linesrc = 0;
    int linetest = 0;
    for (; src > 10 - (!type); src -= 10 - type) {
        type = type == 0;
        linesrc += 1;
    }
    type = 1;
    for (; test > 10 - (!type); test -= 10 - type) {
        type = type == 0;
        linetest += 1;
    }
    if (linesrc + mod == linetest)
        return (1);
    return (0);
}

int is_adjacent_comp(int comp, int test)
{
    if ((comp + 1 == test || comp - 1 == test) && is_same_line(comp, test, 0))
        return (1);
    if ((comp - 9 == test || comp - 10 == test) && is_same_line(comp, test, -1))
        return (1);
    if ((comp + 9 == test || comp + 10 == test) && is_same_line(comp, test, 1))
        return (1);
    return (0);
}
