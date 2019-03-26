/*
** EPITECH PROJECT, 2019
** langton
** File description:
** main file for the langton project
*/

#include "header.h"

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
    } while (key != KEY_BACKSPACE && key != 'q');
}

void langton(int width, int height, int black_chance,
    enum directions direction)
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

int main(int argc, char const *argv[])
{
    langton(204, 53, 1, EAST);
    return 0;
}
