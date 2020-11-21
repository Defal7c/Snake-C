#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "colors.h"

//stats
int score;
char MOVE[] = "c";

int lvlSize = 7;

int snakecoords[2];
int applecoords[2];

//Main Window
int game_height = 9;
int game_width = 9;
int game_y = 7;
int game_x = 5;

//Hud Window
int hud_height = 5;
int hud_width = 15;
int hud_x = 0;
int hud_y = 0;

//art
char BG = 'X';
char SNK = 'O';
char APP = 'G';


void MakeGrid()
{
    WINDOW * mainwin = newwin(game_height,game_width,game_y,game_x);
    box(mainwin,0,0);

    //HUD
    WINDOW * hud = newwin(hud_height, hud_width, hud_y, hud_x);
    box(hud,0,0);
    mvwprintw(hud,1,1,"SCORE: %d\n", score);
    mvwprintw(hud,2,1,"Snake: %d, %d\n", snakecoords[0], snakecoords[1]);
    mvwprintw(hud,3,1,"Apple: %d, %d\n", applecoords[0], applecoords[1]);

    for(int i = 1; i < lvlSize + 1; i++)
    {
        for(int y = 1; y < lvlSize + 1; y++)
        {
            if(applecoords[0] == y && applecoords[1] == i)
            {
                Red();
                mvwaddch(mainwin,applecoords[1],applecoords[0],APP);
                ResetColors();
            }else if(snakecoords[0] == y && i == snakecoords[1])
            {   
                Yellow();
                mvwaddch(mainwin,snakecoords[1],snakecoords[0],SNK);
                ResetColors();
            }else 
            {
                mvwaddch(mainwin,i,y, BG);
            }
        }
    }
    wrefresh(mainwin);
    wrefresh(hud);
}

void Movement()
{
    printf("Choose direction: \n");
    scanf("%s", MOVE);
    //printf("%s\n", MOVE);

    //strcmp

    if(strcmp(MOVE, "u") == 0)
    {
        if(snakecoords[1] != 0) snakecoords[1]--;
    }else if(strcmp(MOVE, "d") == 0)
    {
        if(snakecoords[1] != lvlSize - 1) snakecoords[1]++;
    }else if(strcmp(MOVE, "l") ==0)
    {
        if(snakecoords[0] != 0) snakecoords[0]--;
    }else if(strcmp(MOVE, "r") == 0)
    {
        if(snakecoords[0] != lvlSize - 1) snakecoords[0]++;
    }
}

void randomPOS()
{
    srand(time(NULL));
    snakecoords[0] = rand() % 7;
    snakecoords[1] = rand() % 7;

    // snakecoords[0] = 4;
    // snakecoords[1] = 4;

    applecoords[0] = rand() % 7;
    applecoords[1] = rand() % 7;
}

void Collision()
{
    if(snakecoords[0] == applecoords[0])
    {
        if(snakecoords[1] == applecoords[1])
        {
            score++;
            applecoords[0] = rand() % 7;
            applecoords[1] = rand() % 7;
        }
    }
}