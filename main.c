#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int playing = 1;

char MOVE[] = "";

//stats
int score;

//art
char * BG = "X";
char * SNK = "O";
char * APP = "G";

//coords
int lvlSize = 7;
int snakecoords[2];
int applecoords[2];

//voids
int row = 0;
void MakeGrid(void);
void Movement(void);
void randomPOS(void);
void Collision(void);

#pragma region Colors
void Red()
{
    printf("\033[31m");
}

void Yellow()
{
    printf("\033[33m");
}

void ResetColors()
{
    printf("\033[0m");
}

#pragma endregion

int main()
{
    randomPOS();
    while(playing == 1)
    {
        printf("SCORE: %d\n", score);
        Collision();
        MakeGrid();
        Movement();
    }
    return 0;
}

void randomPOS()
{
    srand(time(NULL));
    snakecoords[0] = rand() % 7;
    snakecoords[1] = rand() % 7;

    applecoords[0] = rand() % 7;
    applecoords[1] = rand() % 7;
}

void MakeGrid()
{
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

    if(strcmp(MOVE, "up") == 0) 
    { 
        char MOVE[] = ""; 
        if(snakecoords[1] == 0) return;
        snakecoords[1]--; 
    }
    if(strcmp(MOVE, "down") == 0) 
    { 
        char MOVE[] = ""; 
        if(snakecoords[1] == lvlSize - 1) return;
        snakecoords[1]++;     
    }
    
    if(strcmp(MOVE, "left") == 0) 
    {
        char MOVE[] = ""; 
        if(snakecoords[0] == 0) return;
        snakecoords[0]--; 
    }
    if(strcmp(MOVE, "right") == 0) 
    { 
        char MOVE[] = ""; 
        if(snakecoords[0] == lvlSize -1) return;    
        snakecoords[0]++; 
    }
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