/*
** EPITECH PROJECT, 2019
** langton
** File description:
** main file for the langton project
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

static bool str_isnum(char const *str)
{
    if (NULL == str)
        return false;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

static void display_help(char const *prgm)
{
    printf("USAGE : %s LINES COLS BLACK_PRCT DIRECTION\n\n", prgm);
    printf("LINES and COLS : positive integers (grid dimensions)\n");
    printf("BLACK_PRCT : positive integer <= 100 ");
    printf("(chance for each cell to start as black)\n");
    printf("DIRECTION : NORTH, EAST, SOUTH, WEST ");
    printf("(the ant's direction at start)\n\n");
    printf("DEFAUT : %s 204 53 0 NORTH\n", prgm);
}

static int check_args(int argc, char const *argv[])
{
    char const *direct[] = {
        "NORTH", "North", "north",
        "EAST", "East", "east",
        "SOUTH", "South", "south",
        "WEST", "West", "west"
    };

    if (!str_isnum(argv[1]) || !str_isnum(argv[2]) || !str_isnum(argv[3]) ||
        atoi(argv[1]) < 0 || atoi(argv[2]) < 0 || atoi(argv[3]) < 0 ||
        atoi(argv[3]) > 100) {
        display_help(argv[0]);
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        if (!strcmp(direct[i * 3], argv[4]) ||
            !strcmp(direct[i * 3 + 1], argv[4]) ||
            !strcmp(direct[i * 3 + 2], argv[4])) {
            langton(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), i);
            return 0;
        }
    }
    display_help(argv[0]);
    return 1;
}

int main(int argc, char const *argv[])
{
    if (2 == argc && !strcmp("-h", argv[1])) {
        display_help(argv[0]);
        return 0;
    } else if (1 == argc) {
        langton(204, 53, 0, NORTH);
        return 0;
    } else if (argc != 5) {
        display_help(argv[0]);
        return 1;
    }
    return check_args(argc, argv);
    return 0;
}
