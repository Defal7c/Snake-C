#include <ncurses.h>

#define BG_GRASS 1
#define EMPTY 1
#define APPLE_GRASS 2
#define SNAKE_GRASS 3
 
void Colors(void)
{
    start_color();
    init_pair(BG_GRASS, COLOR_GREEN, COLOR_GREEN);
    init_pair(APPLE_GRASS, COLOR_RED, COLOR_GREEN);
    init_pair(SNAKE_GRASS, COLOR_YELLOW, COLOR_GREEN);
}