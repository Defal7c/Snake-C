#include <stdio.h>
#include <string.h>

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
