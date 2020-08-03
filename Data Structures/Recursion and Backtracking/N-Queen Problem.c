//Given  a Chessboard of size NxN, place N queens such that no queen can kill another queen where N>0.
//refer YouTube: Prateek Jain
//Question also known N-Queen problem

#include<stdio.h>
#include<stdbool.h>
#define N 32

void print_solution(int board[N][N])//print the values
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}


//check whether a place is safe to place a queen
bool is_safe(int board[N][N], int row, int col)
{
    int i,j;

    for(i=0;i<col;i++)//check leftside
        if(board[row][i] == 1)
            return false;

    for(i=row,j=col;i<=N&&j<=0;i++,j--)//check lower left diagonal
        if(board[i][j] == 1)
            return false;

    for(i=row,j=col;i>=0&&j>=0;i--,j--)//check upper left diagonal
        if(board[i][j] == 1)
            return false;

/*
    We wont check right side in any manner cuz we havent gone there for any insertion of queens. So if there are no
    queens, why to check
*/

    return true;
}


bool solve_n_queen(int board[N][N], int col)
{
    if(col >= N)//If all queens are placed then return true
        return true;

    /*Consider the column 'col' and try placing
       this queen in all rows one by one*/
    for(int i=0;i<N;i++)
    {
         /* Check if the queen can be placed on
          board[i][col] */
        if(is_safe(board,i,col))
        {
            board[i][col] = 1;//placing the queen

            /* recursion to place rest of the queens */
            if(solve_n_queen(board, col+1))
                return true;

            /*If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            board[i][col] = 0;//BACKTRACK
        }
    }

     /* If the queen cannot be placed in any row in
        this colum col  then return false */
    return false;
}

bool solve()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    if (solve_n_queen(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }

    print_solution(board);
    return true;
}


// driver program to test above function
int main()
{
    solve();
    return 0;
}


