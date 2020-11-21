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
void Movement(void);
void Collision(void);

int main()
{
    initscr();
    //raw();

    SelectMenu();
    randomPOS();
    while(playing == 1)
    {
        Collision();
        MakeGrid();
        Movement();
    }
    endwin();
    return 0;
}
