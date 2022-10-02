import java.util.Arrays;



public class sudokuSolver {
    public static void main(String[] args) {
       int grid[][] = {

                         { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                         { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                         { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                         { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                         { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                         { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                         { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                         { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                         { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
        };
       
     solver(grid);
        for (int[] ints : grid) {
            System.out.println(Arrays.toString(ints));
        }
    }

    public static boolean solver(int[][] grid)
    {
        for(int i=0;i<grid.length;i++)
        {
            for(int j=0;j<grid[i].length;j++)
            {
                // empty cell
                if(grid[i][j]==0)
                {
                    for(int num=1;num<=9;num++)
                    {
                        if(isValid(i,j,grid, num))
                        {
                            grid[i][j]=num;

                            //recursive call
                            if(solver(grid))
                            {
                                return true;
                            }
                           
                            //backtrack
                            grid[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean isValid(int row,int col,int[][] board,int num)
    {
        //check for row
        for (int i = 0; i < board.length; i++) {
            if(board[row][i]==num) return false;
        }

        //check for column
        for (int r = 0; r < board.length; r++)
        {
            if (board[r][col] == num)
            {
                return false;
            }
        }

        //check 3*3 box
        int sqrt=(int)Math.sqrt(board.length);
        int rowStart=row-row%sqrt;
        int colStart=col-col%sqrt;

        for(int r=rowStart;r<rowStart+sqrt;r++)
        {
            for(int c=colStart;c<colStart+sqrt;c++)
            {
                if(board[r][c]==num) return false;
            }
        }

        return true;
    }
}
