#include <iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{

    int col_size = matrix[0].size();
    int row_size = matrix.size();
    int col = true;

    for (int i = 0; i < row_size; i++)
    {
        if (matrix[i][0] == 0)
        {
            col = false;
            cout<<col<<endl;
        }
        for (int j = 1; j < col_size; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = row_size - 1; i >= 0; i--)
    {
        for (int j = col_size - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
        if (col == false)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix{

        {-4,-2147483648,6,-7,0},
        {-8,6,-8,-6,0},
        {2147483647,2,-9,-6,-10}
    };
    
    setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
