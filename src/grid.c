#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "controls.h"
#include "colors.h"
#include "stats.h"

//stats
char MOVE;

int lvlSize = 7; 

int snakecoords[2];
int applecoords[2];

//last dir 0 means Y
//last dir 1 means X
int lastDir[]= {0}; 
int lastX[]= {0};
int lastY[] = {0};


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
char BG = ' ';
char SNK = 'O';
char APP = 'G';


void Movement(char);

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

    int offset = 1;
    for(int i = 0; i < lvlSize; i++)
    {
        for(int y = 0; y < lvlSize; y++)
        {
            // for(int ld = 0; ld < score + 1; ld++)
            // {
            //     if(score != 0)
            //     {
            //         if(lastDir[ld] == 0) mvwaddch(mainwin,snakecoords[0] + offset - lastY[ld],snakecoords[1]+offset,SNK);
            //         else mvwaddch(mainwin,snakecoords[0]+offset,snakecoords[1]+offset - lastX[ld],SNK);
            //     }
            // }
            if(applecoords[0] == y && applecoords[1] == i)
            {
                attron(COLOR_PAIR(APPLE_GRASS));
                mvwaddch(mainwin,applecoords[1] + offset,applecoords[0] + offset,APP);
                attroff(COLOR_PAIR(APPLE_GRASS));
            }else if(snakecoords[0] == y && i == snakecoords[1])
            {   
                attron(COLOR_PAIR(3));
                mvwaddch(mainwin,snakecoords[1] + offset,snakecoords[0] + offset,SNK);
                attroff(COLOR_PAIR(3));
            }else 
            {
                attron(COLOR_PAIR(1));
                mvwaddch(mainwin,i+ offset,y+ offset, BG);
                attroff(COLOR_PAIR(1));
            }
        }
    }
    wrefresh(mainwin);
    wrefresh(hud);


    MOVE = wgetch(mainwin);
    Movement(MOVE);
}

void UpdateBody(int _dir, int stuff)
{
    lastDir[score] = _dir;
    if(_dir == 0)
    {
        lastY[score] = -stuff;
        lastX[score] = 0;
    }else
    {
        lastX[score] = -stuff;
        lastY[score] = 0;
    }
}

void Movement(char _dir)
{
    switch(_dir)
    {
        case UP:
            if(snakecoords[1] != 0) snakecoords[1]--;
            UpdateBody(0,1);
            break;
        case DOWN:
            if(snakecoords[1] != lvlSize -1) snakecoords[1]++;
            UpdateBody(0,-1);
            break;
        case LEFT:
            if(snakecoords[0] != 0) snakecoords[0]--;
            UpdateBody(1,-1);
            break;
        case RIGHT:
            if(snakecoords[0] != lvlSize -1) snakecoords[0]++;
            UpdateBody(1,1);
            break;
        default:
            break;
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