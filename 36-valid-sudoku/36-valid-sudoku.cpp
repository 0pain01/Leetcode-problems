class Solution {
public:
    bool isValid(int row,int col,char c,vector<vector<char>>board)
    {
        for(int i=0;i<9;i++)
        {
            
            if(i!=row && board[i][col]==c)
                return false;
            
            if(i!=col && board[row][i]==c)
                return false;
            
            int x = 3*(row/3)+i/3;
            int y = 3*(col/3)+i%3;
            if(x!=row && y!=col&& board[x][y]==c)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
         for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    continue;
                }
                else
                {
                    if(!isValid(i,j,board[i][j],board))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};