class Solution {
public:
    bool canPlace(vector<vector<char>>& board, int i, int j, char num) {
        for (int m = 0; m < 9; m++)
            if ((m!=i && board[m][j]== num) || (m!=j && board[i][m]== num))
                return false;
        int gridX = i - (i%3), gridY = j - (j%3);
        for (int m = 0; m < 3; m++){
            for (int n = 0; n < 3; n++) {
                if (gridX+m!=i && gridY+n!=j)
                    if (board[gridX+m][gridY+n] == num)
                        return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != '.')
            if (i==8 && j==8)
                return true;
            else
                if (j<8)
                    return solve(board,i,j+1);
                else
                    return solve(board,i+1,0);
        for (int m=0; m<9; m++){
            if (canPlace(board, i, j, '1'+m)){
                board[i][j]='1'+m;
                if (i==8 && j==8)
                    return true;
                if (j<8){
                    if (solve(board, i, j+1)) 
                        return true;
                }
                else{
                    if (solve(board, i+1, 0))
                        return true;
                }
                board[i][j]='.';
            }
        }
        return false;
                
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};

/* Sample Input:
[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
*/
