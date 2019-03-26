/*
** EPITECH PROJECT, 2019
** langton
** File description:
** header file for the langton project
*/

#ifndef HEADER_H_
	#define HEADER_H_

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <time.h>
    #include <ncurses.h>

    #define X 0
    #define Y 1
    #define WHITE 0
    #define BLACK 1
    #define SLEEP 1000

    enum directions
    {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    typedef struct langton
    {
        int width;
        int height;
        char **grid;
        int x;
        int y;
        enum directions direction;
        int turns;
    } langton_t;

    langton_t *init_langton(int width, int height,
        int black_chance, enum directions direction);

    void destroy_langton(langton_t *langton);    

    void print_langton(langton_t *langton);

    void move_ant(langton_t *langton);

    int pause_loop(void);

#endif /* !HEADER_H_ */
