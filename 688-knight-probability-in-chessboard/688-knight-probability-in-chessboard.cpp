class Solution {
public:
    int dx[8]={-2,-1, 1, 2, 2, 1,-1,-2};
    int dy[8]={ 1, 2, 2, 1,-1,-2,-2,-1};
    
    bool isvalid(int i,int j,int n)
    {
        if(i>=0 && i<n && j>=0 && j<n)
            return true;
        return false;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> curr(n,vector<double>(n,0));
        vector<vector<double>> next(n,vector<double>(n,0));
        curr[row][column]=1;
        
        for(int m=1;m<=k;m++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(curr[i][j]!=0)
                    {
                        for(int l=0;l<8;l++)
                        {
                            if(isvalid(i+dx[l],j+dy[l],n))
                                next[i+dx[l]][j+dy[l]]+=(curr[i][j]/8.0);
                        }
                    }
                }
            }
            curr=next;
            
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    next[i][j]=0;
        }
        
        double sum=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<curr[i][j]<<" ";
                sum+=curr[i][j];
            }
            cout<<endl;
        }
        return sum;
    }
};