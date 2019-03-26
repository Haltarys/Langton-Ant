/*
** EPITECH PROJECT, 2019
** langton
** File description:
** moves the ant through the grid
** if the ant is on a white cell, it turns right
** else (it is on a black cell), it turns left
*/

#include "header.h"

void move_ant(langton_t *langton)
{
    int moves[4][2] = {
        {0, -1 * (langton->y > 0)}, 
        {1 * (langton->x < langton->width - 1), 0}, 
        {0, 1 * (langton->y < langton->height - 1)}, 
        {-1 * (langton->x > 0), 0}
        };

    if (langton->grid[langton->y][langton->x] == BLACK) {
        // Actually (direction - 1 + 4) % 4
        langton->direction = (langton->direction + 3) % 4;
        langton->grid[langton->y][langton->x] = WHITE;
    } else {
        langton->direction = (langton->direction + 1) % 4;
        langton->grid[langton->y][langton->x] = BLACK;
    }
    langton->x += moves[langton->direction][X];
    langton->y += moves[langton->direction][Y];
}
