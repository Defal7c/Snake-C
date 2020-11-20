#include <stdio.h>
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

//art
char * BG = "X";
char * SNK = "O";
char * APP = "G";

void MakeGrid()
{
    printf("SCORE: %d\n", score);
    printf("Snake: %d, %d\n", snakecoords[0], snakecoords[1]);
    printf("Apple: %d, %d\n", applecoords[0], applecoords[1]);

    for(int i = 0; i < lvlSize; i++)
    {
        for(int y = 0; y < lvlSize; y++)
        {
            if(applecoords[0] == y && applecoords[1] == i)
            {
                Red();
                printf("%s", APP);
                ResetColors();
            }else if(snakecoords[0] == y && i == snakecoords[1])
            {
                Yellow();
                printf("%s", SNK);
                ResetColors();
            }else printf("%s", BG);
        }
    printf("%d", i);
    printf("\n");
    }
}

void Movement()
{
    printf("Choose direction: \n");
    scanf("%s", MOVE);
    printf("%s\n", MOVE);

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