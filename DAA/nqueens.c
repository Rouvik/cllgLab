#include <stdio.h>

#define W 8

int solIndex = 1;

void printBoard(int board[W][W])
{
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < W; j++)
        {
            printf("%c ", board[i][j] == 1 ? 'Q' : '#');
        }
        putchar('\n');
    }
    putchar('\n');
}

int isSafe(int board[W][W], int row, int col)
{
    // check col
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
           return 0;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {   
            return 0;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < W; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return 0;
        }
    }

    return 1;
}

void nqueens(int board[W][W], int row)
{
    if (row == W)
    {
        printf("Solution %d:\n", solIndex);
        printBoard(board);
        solIndex++;
        return;
    }

    for (int j = 0; j < W; j++)
    {
        if (isSafe(board, row, j))
        {
            board[row][j] = 1;
            nqueens(board, row + 1);
            board[row][j] = 0;
        }
    }
}

int main()
{
    int board[W][W] = {0};

    nqueens(board, 0);

    return 0;
}
