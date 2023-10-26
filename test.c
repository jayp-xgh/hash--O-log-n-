#include <stdio.h>
#include <stdlib.h>

int optionLine;
int optionColumn;

char turn = 'X';

typedef struct {
    char typePlayer;
} Player;

typedef struct {
    char Table[3][3];
} Game;

typedef struct {
    int ColumnX[3];
    int LineX[3];
    int ColumnO[3];
    int LineO[3];
  
    int MainDiagonalX;
    int SecondaryDiagonalX;
    int MainDiagonalO;
    int SecondaryDiagonalO;
} GamePositionXO;
