#include <stdio.h>

void Red()
{
    printf("\033[31m");
}

void Yellow()
{
    printf("\e[33m");
}

void ResetColors()
{
    printf("\033[0m");
}