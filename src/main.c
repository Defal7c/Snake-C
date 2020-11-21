#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    SelectMenu();

    randomPOS();
    while(playing == 1)
    {
        system("clear");
        Collision();
        MakeGrid();
        Movement();
    }
    return 0;
}
