/*
** EPITECH PROJECT, 2019
** langton
** File description:
** prints the grid, the ant, and the number of turns
*/

#include <ncurses.h>
#include "header.h"

void print_langton(langton_t *langton)
{
    static char *ant = "^>v<";

    mvprintw((LINES - langton->height) / 2, (COLS - langton->width) / 2,
        "Turns : %i", langton->turns++);    
    for (int y = 0; y < langton->height; y++) {
        for (int x = 0, i = 0, j = 0; x < langton->width; x++) {
            i = (LINES - langton->height) / 2 + y + 1;
            j = (COLS - langton->width) / 2 + x;
            mvprintw(i, j, "%c", (langton->grid[y][x] == BLACK)? '#' : '.');
        }
    }
    mvprintw((LINES - langton->height) / 2 + langton->y + 1,
        (COLS - langton->width) / 2 + langton->x, "%c", ant[langton->direction]);
    refresh();
}
