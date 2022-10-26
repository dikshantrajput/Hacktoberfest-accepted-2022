#include <bits/stdc++.h>

using namespace std;

// function to remove the last placed Queen & returning its column number
int removeQueen(int row, int n, vector< vector<int> > &grid)
{
    if(row == -1)
        return -1;
    
    for(int i=0; i<n; i++)
    {
        if(grid[row][i] == 1)
        {
            grid[row][i] = 0;
            return i;
        }        
    }
}

// function to add a Queen to the grid
void addQueen(int row, int col, vector< vector<int> > &grid)
{
    grid[row][col] = 1;
    return;
}

// function to check if any existing Queen is attacking the new Queen or not
bool attacks(int attackingQueenX, int attackingQueenY, int targetQueenX, int targetQueenY)
{
    if(attackingQueenX == targetQueenX || attackingQueenY == targetQueenY)
        return true;

    int diff = abs(attackingQueenX - targetQueenX);

    if(diff == abs(attackingQueenY - targetQueenY))
        return true;

    return false;
}

// function to check if current column is valid for placing a Queen
bool isValid(int row, int col, int n, vector< vector<int> > &grid)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] == 1)
            {
                if(attacks(i, j, row, col))
                    return false;
            }
        }
    }

    return true;
}

void n_Queen(int row, int col, int n, vector< vector<int> > &grid, bool &allQueensPlaced, bool &noPossibleArrangement)
{
    if(allQueensPlaced || noPossibleArrangement)
        return;

    if(row == -1)
    {
        noPossibleArrangement = true;
        return;
    }

    if(row == n)
    {
        allQueensPlaced = true;
        return;
    }

    if(col == n)
    {
        int lastQueenCol = removeQueen(row-1, n, grid);

        if(lastQueenCol == -1)
        {
            noPossibleArrangement = true;
            return;
        }

        n_Queen(row-1, lastQueenCol+1, n, grid, allQueensPlaced, noPossibleArrangement);
    }

    if(isValid(row, col, n, grid))
    {
        addQueen(row, col, grid);
        n_Queen(row+1, 0, n, grid, allQueensPlaced, noPossibleArrangement);
    }
    else
    {
        n_Queen(row, col+1, n, grid, allQueensPlaced, noPossibleArrangement);
    }
}

int main()
{
    int n;
    cin >> n;

    vector< vector<int> > grid(n, vector<int>(n));

    bool allQueensPlaced = false;   // variable to check if all Queens are placed
    bool noPossibleArrangement = false; // variable to check if there's no possible arrangement

    n_Queen(0, 0, n, grid, allQueensPlaced, noPossibleArrangement);

    if(noPossibleArrangement)
    {
        cout << "There's no possible arrangement" << endl;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }        
    }

    return 0;
}