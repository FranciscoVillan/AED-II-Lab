#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[3][3])
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

char get_winner(char board[3][3])
{
    char winner = '-';
    char holder='-';
    int counter=0;

    for (int i = 0; i < 3; i++)
    {
        //Checking horizontally

        holder = board[i][0];
        for (int j = 0; j < 3; j++)
        {
          
            if (board[i][j]== '-' )
            {
                break;
            }
             else if (board[i][j]==holder)
             {
                counter= counter+1;
                continue;
             }
             
        }
        if (counter==3)
            {
                return holder;
            }
            else
              counter=0;

        //Checking vertically

        holder = board[0][i];
        for (int j = 0; j < 3; j++)
        {
          
            if (board[j][i]== '-' )
            {
                break;
            }
             else if (board[j][i]==holder)
             {
                counter= counter+1;
                continue;
             }
             
        }
        if (counter==3)
            {
                return holder;
            }
            else
              counter=0;



        
        ///

        //Checking diagonally up-left to down-right

        holder = board[0][0];
        for (int j = 0; j < 3; j++)
        {
          
            if (board[j][j]== '-' )
            {
                break;
            }
             else if (board[j][j]==holder)
             {
                counter= counter+1;
                continue;
             }
             
        }
        if (counter==3)
            {
                return holder;
            }
            else
              counter=0;
        



        //Checking down-left to up-right
        holder = board[2][0];
        for (int j = 0; j <3; j++)
        {
          
            if (board[j][2-j]== '-' )
            {
                break;
            }
             else if (board[j][2-j]==holder)
             {
                counter= counter+1;
             }
             
        }
        if (counter==3)
            {
                return holder;
            }
            else
              counter=0;




     
                
    }
    
    return winner;

}
    


bool has_free_cell(char board[3][3])
{
    bool free_cell=false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                return free_cell=true;
                break;
            }
                     
        }
        
    }
    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}