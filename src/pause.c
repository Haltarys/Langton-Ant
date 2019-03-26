/*
** EPITECH PROJECT, 2019
** langton
** File description:
** pauses the simulation and waits for a signal to resume
*/

#include "header.h"

int pause_loop(void)
{
    int res = 0;

    while (res != 'p' && res != ' ' && res != 'q' && res != KEY_BACKSPACE)
        res = getch();
    return res;
}
