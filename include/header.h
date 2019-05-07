/*
** EPITECH PROJECT, 2019
** langton
** File description:
** header file for the langton project
*/

#ifndef HEADER_H_
#define HEADER_H_

static const int X = 0;
static const int Y = 1;
static const int WHITE = 0;
static const int BLACK = 1;
static const int SLEEP = 1000000;

enum directions_id
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
    int direction;
    int turns;
} langton_t;

void langton(int width, int height, int black_chance, int direction);
langton_t *init_langton(int width, int height, int black_chance, int direction);
void destroy_langton(langton_t *langton);
void print_langton(langton_t *langton);
void move_ant(langton_t *langton);
int pause_loop(void);

#endif /* !HEADER_H_ */
