#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "controls.h"


int inMenu = 1;
int OPT = 0;
void MainMenu(void);
void OptionsMenu(void);

char mv[] = "";

void SelectMenu()
{
    while(inMenu == 1)
    {
        if(OPT == 0) MainMenu();
        else if(OPT == 1) inMenu = 0;
        else if(OPT == 2) OptionsMenu();
        //else if(OPT == 4) Manual();
        //else if(OPT == 5) cry();
    }
}

int selected = 1;
char * MENUS[] = { "", "START", "Options", "Manual", "Quit" };

// Logo
int logo_height = 8;
int logo_width = 45;
int logo_y = 0;
int logo_x = 0;

// main window
int main_height = 6;
int main_width = 15;
int main_y = 10;
int main_x = 15;

//Cursor pos
int cursorPOS[2] = {0, 0};


void MainMenu()
{
    refresh();
    WINDOW * logo = newwin(logo_height, logo_width,logo_y,logo_x);
    box(logo, 0,0);
    mvwprintw(logo,1,1,"  ____      _          _       _           ");
    mvwprintw(logo,2,1," / ___|___ | |__  _ __(_)_ __ | |__   __ _ ");
    mvwprintw(logo,3,1,"| |   / _ `| '_ `| '__| | '_ `| '_ ` / _` |");
    mvwprintw(logo,4,1,"| |__| (_) | |_) | |  | | | | | | | | (_| |");
    mvwprintw(logo,5,1,"`____`____/|_.__/|_|  |_|_| |_|_| |_|`__,_|");
    mvwprintw(logo,6,1,"                             Simulator 2020");
    wrefresh(logo);
    
    WINDOW * mainwindow = newwin(main_height, main_width, main_y, main_x);
    box(mainwindow, 0,0);
    
    for(int i = 1; i < 5; i++)
    {
        mvwaddch(mainwindow, i,1,'[');
        if(i == selected) 
        { 
            cursorPOS[0] == i;
            cursorPOS[1] == 1;
            mvwaddch(mainwindow, i, 2,'*'); 
        }else{ 
            mvwaddch(mainwindow, i,2,'\0');
        }
        mvwaddch(mainwindow, i ,3,']');
        mvwprintw(mainwindow, i,6,"%s", MENUS[i]);
    }
    int ch = wgetch(mainwindow);
    if(ch == ENTER) OPT = selected;
    if(ch == DOWN) { if(selected != 4) selected++; }
    if(ch == UP) { if(selected != 0) selected--; }

    wrefresh(logo);
    wrefresh(mainwindow);
}


int sel = 0;
int MAXOPT = 1;
int COLORS = 1;
char * OPTIONS[] = {"Disable Colors", "Go Back"};

//Options Window
int optmenu_height = 6;
int optmenu_width = 21;
int optmenu_x = 10;
int optmenu_y = 10;

//Options Logo
int opt_height = 8;
int opt_width = 45;

void OptionsMenu()
{
    clear();
    WINDOW * opt = newwin(opt_height, opt_width, logo_y, logo_x);
    box(opt, 0,0);
    //mvwprintw(opt,1,1,"%d", sel);
    mvwprintw(opt,1,1,"  ___        _   _                 ");
    mvwprintw(opt,2,1," / _ ` _ __ | |_(_) ___  _ __  ___ ");
    mvwprintw(opt,3,1,"| | | | '_ `| __| |/ _ `| '_ `/ __|");
    mvwprintw(opt,4,1,"| |_| | |_) | |_| | (_) | | | `__ `");
    mvwprintw(opt,5,1,"` ___/| .__/` __|_|`___/|_| |_|___/");
    mvwprintw(opt,6,1,"      |_|                          ");
    wrefresh(opt);

    WINDOW * optmenu = newwin(optmenu_height, optmenu_width, optmenu_y, optmenu_x);
    box(optmenu,0,0);
    //this is the best code I've ever written in my entire life.
    for(int i = 0; i < 2; i++)
    {
        mvwaddch(optmenu,i+1,1,'[');
        if(i == sel)
        {
            cursorPOS[0] = i+1;
            cursorPOS[1] = 2;
            mvwaddch(optmenu, i+1,2,'*'); 
        }else mvwaddch(optmenu, i+1,2, '\0');
        mvwaddch(optmenu,i+1,3,']');
        mvwprintw(optmenu,i+1,6,"%s", OPTIONS[i]);
    }
    int ch = wgetch(optmenu);

    if(ch == ENTER)
    {
        if(sel == 0) 
        {
            if(COLORS == 1) 
            {
                OPTIONS[0] == "Enable Colors";
                COLORS = 0;
            }else 
            {
                OPTIONS[0] == "Disable Colors";
                COLORS == 1;
            }
        }
        if(sel == 1) OPT = 0;
    }
    switch(ch)
    {
        case DOWN:
            if(sel == MAXOPT) break;
            sel++;
            break;
        case UP:
            if(sel == 0) break;
            sel--;
            break;
        default:
            break;
    }
    wrefresh(opt);
    wrefresh(optmenu);
}