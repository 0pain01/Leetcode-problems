class Solution {
public:
    bool isSafe(int row,int col,vector<string>ans,int n)
    {
        int row1=row;
        int col1=col;
        while(row>=0 && col>=0)
        {
            if(ans[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        
        row=row1; col=col1;
        
        while(col>=0)
        {
            if(ans[row][col]=='Q')
                return false;
            col--;
        }
        
        col=col1;
        while(row<=n-1 && col>=0)
        {
            if(ans[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        
        return true;
        
    }
    void helper(int col, vector<vector<string>>&res, vector<string>&ans, int n)
    {
        if(col==n)
        {
            res.push_back(ans);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,ans,n))
            {
                ans[row][col]='Q';
                helper(col+1,res,ans,n);
                ans[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>ans(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            ans[i]=s;
        }
        
        helper(0,res,ans,n);
        return res;
        
    }
};