class Solution {
public:
    int n,m;
    int dx[4]={0,1, 0,-1};
    int dy[4]={1,0,-1, 0};
    
    bool helper(vector<vector<char>>& board, string word,int i, int j, int index){
        if(index>=word.size()) return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[index])
            return false;
        char temp = board[i][j];
        board[i][j]='#';
        for(int k=0;k<4;k++)
        {
            if(helper(board,word,i+dx[k],j+dy[k],index+1))
               return true;
        }
        board[i][j]=temp;
    return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(helper(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};