class Solution {
public:
    int solver(int a, int x)
    {
        int b=0;
        if(a==0)
        {
            if(x==3)
                b=1;
        }
        else
        {
            if(x==3||x==2)
                b=1;
            else if(x>3 || x<2)
                b=0;
        }
        return b;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>temp=board;
        
        if(n==1)
        {
            if(m==1)
            {
                board[0][0]=0;
                return;
            }
            else
            {
                for(int i=0;i<m;i++)
                {
                    if(i==0||i==m-1)
                    {
                        temp[0][i]=0;
                    }
                    else
                    {
                        temp[0][i]=solver(board[0][i],board[0][i+1]+board[0][i-1]);
                    }
                }
                board=temp;
                return;
            }
        }
        
        if(m==1)
        {
                for(int i=0;i<n;i++)
                {
                    if(i==0||i==n-1)
                    {
                        temp[i][0]=0;
                    }
                    else
                    {
                        temp[i][0]=solver(board[i][0],board[i+1][0]+board[i-1][0]);
                    }
                }
                board=temp;
                return;
        }
        
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=0;
                if(i==0)
                {
                    if(j==0)
                    {
                        x=board[i][j+1]+board[i+1][j+1]+board[i+1][j];
                    }
                    else if(j==m-1)
                    {
                        x=board[i][j-1]+board[i+1][j-1]+board[i+1][j];
                    }
                    else
                    {
                        x=board[i][j+1]+board[i+1][j+1]+board[i+1][j]+board[i][j-1]+board[i+1][j-1];
                        
                    }
                    temp[i][j]=solver(board[i][j],x);
                }
                else if(j==0)
                {
                    if(i==n-1)
                    {
                        x=board[i][j+1]+board[i-1][j]+board[i-1][j+1];
                    }
                    else
                    {
                        x=board[i-1][j]+board[i-1][j+1]+board[i][j+1]+board[i+1][j+1]+board[i+1][j];
                    }
                    temp[i][j]=solver(board[i][j],x);
                }
                else if(j==m-1)
                {
                    if(i==n-1)
                    {
                        x=board[i][j-1]+board[i-1][j]+board[i-1][j-1];
                    }
                    else
                    {
                        x=board[i-1][j]+board[i-1][j-1]+board[i][j-1]+board[i+1][j-1]+board[i+1][j];
                    }
                    temp[i][j]=solver(board[i][j],x);
                }
                else if(i==n-1)
                {
                    x=board[i][j-1]+board[i-1][j-1]+board[i-1][j]+board[i-1][j+1]+board[i][j+1];
                    temp[i][j]=solver(board[i][j],x);
                }
                else
                {
                    x=board[i][j-1]+board[i+1][j-1]+board[i-1][j]+board[i-1][j+1]+board[i][j+1]+
                        board[i+1][j+1]+board[i+1][j]+board[i-1][j-1];
                    temp[i][j]=solver(board[i][j],x);
                }
            }
        }
        board=temp;
    }
};