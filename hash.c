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

void renderTable(Game *game) {
    int i = 0, j = 0;

    while (i <= 2) {
        while (j <= 2) {
            printf("%c", game->Table[i][j]);
            if (j != 2)
                printf(" | ");
            fflush(stdin);
            j++;
        }
        if (i != 2)
            printf("\n--|---|--\n");
        i++;
        j = 0;
    }
}

int validationForPosition(Game *game, int optionLine, int optionColumn, char turn) {
    if (optionLine > 2 || optionColumn > 2) {
        printf("\n Erro: voce escolheu uma posicao inexistente");
        return 1;
    }
    if (game->Table[optionLine][optionColumn] != ' '){
        printf("\n Erro: voce escolheu uma posicao preenchida");
        return 1;
    }
    return 0;
}

int insertTable(Game *game, GamePositionXO *gamePosition, int optionLine, int optionColumn, char turn, int round) {
    
    game->Table[optionLine][optionColumn] = turn;
    
    if (turn == 'X') {
        gamePosition->ColumnX[optionColumn] += 1;
        gamePosition->LineX[optionLine] += 1;
        if(optionColumn == optionLine){
            gamePosition->MainDiagonalX += 1;
        }
        if((optionColumn + optionLine) == 2) {
            gamePosition->SecondaryDiagonalX += 1;
        }
        if (gamePosition->ColumnX[optionColumn] == 3 || gamePosition->LineX[optionLine] == 3|| gamePosition->MainDiagonalX == 3 || gamePosition->SecondaryDiagonalX == 3) {
            return 1; 
        }
    }
    else if (turn == 'O') {
        gamePosition->ColumnO[optionColumn] += 1;
        gamePosition->LineO[optionLine] += 1;
        
        if(optionColumn == optionLine){
            gamePosition->MainDiagonalO += 1;
        }
        
        if((optionColumn + optionLine) == 2){
                 gamePosition->SecondaryDiagonalO += 1;
        }
    
        if (gamePosition->ColumnO[optionColumn] == 3 || gamePosition->LineO[optionLine] == 3 ||  gamePosition->MainDiagonalO == 3 || gamePosition->SecondaryDiagonalO == 3)
            return 1;
    }
    return 0;
}

void roundGame() {
    printf("\n turn do jogador %c:", turn);
    fflush(stdin);
    printf("\n Escolha a posicao (linha) %c:", turn);
    scanf("%d", &optionLine);
    printf("\n Escolha a posicao (coluna) %c:", turn);
    scanf("%d", &optionColumn);
}

int main() {
    Game game = {{
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    }};

    renderTable(&game);
    
    Player player1;
    Player player2;
    GamePositionXO gamePosition = {0, 0.0f, '\0'};
    
    int round = 1;
    player1.typePlayer = 'X';
    player2.typePlayer = 'O';

    while (1) {
        roundGame();
        if (validationForPosition(&game, optionLine, optionColumn, turn)){
            continue;
        }
        
        int result = insertTable(&game, &gamePosition, optionLine, optionColumn, turn, round);
        
        if (result == 1){
            renderTable(&game);
            printf("\nO jogador %c ganhou!", turn);
            break;
        }

        renderTable(&game);

        turn = (turn == 'X' ? 'O' : 'X');
        round++;
    }
}

