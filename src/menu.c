#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>

int inMenu = 1;
char OPT[] = "cu";
void MainMenu(void);
void OptionsMenu(void);

void SelectMenu()
{
    while(inMenu == 1)
    {
        if(strcmp(OPT, "cu") == 0)
        {
            MainMenu();
        }else if(strcmp(OPT, "2") == 0)
        {
            OptionsMenu();
        }
    }
}

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

    printf("1 - START GAME\n");
    printf("2 - OPTIONS\n");
    printf("3 - EXIT\n");
    scanf("%s", OPT);
    printf("%s\n", OPT);
    
    if(strcmp(OPT, "1") == 0)
    {
        inMenu = 0;
    }
}

int sel = 0;
int MAXOPT = 1;
char * OPTIONS[] = {"Disable Colors", "Cry out loud"};
char mv[] = "";

int key;

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
    switch(getch())
    {
        case 80:
            if(sel != MAXOPT) sel++;
            break;
        default:
            break;
    }

    // if(strcmp(mv, "d") == 0) if(sel != MAXOPT) sel++;
    // else if(strcmp(mv, "u") == 0) if(sel != 0) sel--;
}