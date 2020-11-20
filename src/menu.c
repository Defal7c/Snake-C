#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "controls.h"

int inMenu = 1;
int OPT = 1;
void MainMenu(void);
void OptionsMenu(void);

char mv[] = "";

void SelectMenu()
{
    while(inMenu == 1)
    {
        if(OPT == 0) inMenu = 0;
        else if(OPT == 1) MainMenu();
        else if(OPT == 2) OptionsMenu();
    }
}

int selected = 0;
char * MENUS[] = { "START", "Options", "Manual", "Quit" };
char ch;

void MainMenu()
{
    system("clear");
    printf("-------------------------------------------\n");
    printf("  ____      _          _       _           \n");
    printf(" / ___|___ | |__  _ __(_)_ __ | |__   __ _ \n");
    printf("| |   / _ `| '_ `| '__| | '_ `| '_ ` / _` |\n");
    printf("| |__| (_) | |_) | |  | | | | | | | | (_| |\n");
    printf("`____`____/|_.__/|_|  |_|_| |_|_| |_|`__,_|\n");
    printf("                             Simulator 2020\n");
    printf("-------------------------------------------\n");

    for(int i = 0; i < 4; i++)
    {
        printf("[");
        if(i == selected) printf("*"); else printf(" ");
        printf("] - ");
        printf("%s\n", MENUS[i]);
    }
    ch = fgetc(stdin);
    if(ch==0x0A) OPT = selected;
    else if(ch == 's') { if(selected != 3) selected++; } 
    else if(ch == 'w') { if(selected != 0) selected--; }
}


int sel = 0;
int MAXOPT = 1;
char * OPTIONS[] = {"Disable Colors", "Go Back"};
int arrow;

void OptionsMenu()
{
    system("clear");
    printf("-------------------------------------------\n");
    printf("  ___        _   _                 \n");
    printf(" / _ ` _ __ | |_(_) ___  _ __  ___ \n");
    printf("| | | | '_ `| __| |/ _ `| '_ `/ __|\n");
    printf("| |_| | |_) | |_| | (_) | | | `__ `\n");
    printf("` ___/| .__/` __|_|`___/|_| |_|___/\n");
    printf("      |_|                          \n");
    printf("-------------------------------------------\n");
    printf("\n");

    //this is the best code I've ever written in my entire life.
    for(int i = 0; i < 2; i++)
    {
        printf("[");
        if(i == sel) printf("*"); else printf(" ");
        printf("] - ");
        printf("%s\n", OPTIONS[i]);
    }
    scanf("%s", mv);

    if(strcmp(mv, DOWN) == 0)
    {
        if(sel != MAXOPT) sel++;
    }else if(strcmp(mv, UP) == 0) if(sel != 0) sel--;
}