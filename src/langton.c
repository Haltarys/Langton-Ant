/*
** EPITECH PROJECT, 2019
** langton
** File description:
** initialises the structure with the given parameters
*/

#include "header.h"

void destroy_langton(langton_t *langton)
{
    for (int i = 0; i < langton->height; i++)
        free(langton->grid[i]);
    free(langton->grid);
    free(langton);
}

static char **init_grid(int width, int height, int black_chance)
{
    char **res = calloc(height, sizeof(char *));

    srand(time(NULL));
    for (int y = 0; y < height; y++) {
        res[y] = calloc(width, sizeof(char));
        for (int x = 0; x < width; x++) {
            if (rand() % 100 < black_chance)
                res[y][x] = BLACK;
        }
    }
    return res;
}

langton_t *init_langton(int width, int height,
    int black_chance, enum directions direction)
{
    langton_t *res = calloc(1, sizeof(langton_t));

    res->width = width;
    res->height = height;
    res->x = width / 2;
    res->y = height / 2;
    res->direction = direction;
    res->grid = init_grid(width, height, black_chance);
    res->turns = 0;
    return res;
}
