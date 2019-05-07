/*
** EPITECH PROJECT, 2019
** langton
** File description:
** initialises the structure with the given parameters
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <ncurses.h>
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

langton_t *init_langton(int width, int height, int black_chance, int direction)
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

static void gameloop(langton_t *langton)
{
    int key = 0;

    do {
        print_langton(langton);
        move_ant(langton);
        usleep(SLEEP);
        key = getch();
        if ('p' == key || ' ' == key)
            key = pause_loop();
    } while (key != KEY_BACKSPACE && key != 'q' && key != 'Q');
}

void langton(int width, int height, int black_chance, int direction)
{
    langton_t *langton = init_langton(width, height, black_chance, direction);

    initscr();
    cbreak();
    timeout(1);
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    gameloop(langton);
    endwin();
    destroy_langton(langton);
}
