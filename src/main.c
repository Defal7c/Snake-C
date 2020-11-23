#include <stdio.h>
#include <string.h>

#ifndef _WIN32
    #include <ncurses.h>
#else
    #include <conio.h>
#endif 

int playing = 1;

//voids
int row = 0;

void SelectMenu(void);

void randomPOS(void);
void MakeGrid(void);
void Collision(void);

int main()
{
    initscr();
    //raw();
    if(!has_colors())
    {
        printw("Terminal doesn't support colors!!");
        getch();
        return -1;
    }
    SelectMenu();
    clear();
    randomPOS();
    while(playing == 1)
    {
        refresh();
        Collision();
        MakeGrid();
    }
    endwin();
    return 0;
}
