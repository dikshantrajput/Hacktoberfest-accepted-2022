#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printSolution(int N, int board[N][N]) 
{ 
    static int k = 1; 
    printf("%d:\n",k++); 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    }  
    printf("\n"); 
} 
  
int isSafe(int N, int board[N][N], int row, int col) 
{ 
    int i, j; 
  
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return 0; 
  
    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j]) 
            return 0; 
  
    for (i=row, j=col; j>=0 && i<N; i++, j--) 
        if (board[i][j]) 
            return 0; 
  
    return 1; 
} 
  
int solveNQUtil(int N, int board[N][N], int col) 
{ 
    if (col == N) 
    { 
        printSolution(N, board); 
        return 1; 
    } 
  
    int res = 0; 
    for (int i = 0; i < N; i++) 
    { 
        if ( isSafe(N, board, i, col) ) 
        { 
            board[i][col] = 1; 
  
             res = solveNQUtil(N, board, col + 1) || res; 
  
            board[i][col] = 0;  
        } 
    } 
  
    return res; 
} 
  
void solveNQ(int N) 
{ 
    int board[N][N]; 
    memset(board, 0, sizeof(board)); 
  
    if (solveNQUtil(N, board, 0) == 0) 
    { 
        printf("Solution does not exist"); 
        return ; 
    } 
  
    return ; 
} 
  
int main() 
{ 
    int N=5;
    int board[N][N]; 
    memset(board, 0, sizeof(board)); 
  
    if (solveNQUtil(N, board, 0) == 0) 
    { 
        printf("Solution does not exist");
    }
    
    return 0; 
}