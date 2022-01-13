class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        int size = trust.size();
        
        if(size==0 && n==1)
            return n;
        
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=0;
            }
        }
        
        for(int i=0;i<size;i++)
        {
            dp[trust[i][0]][trust[i][1]]=1;
        }
        
        
      vector<pair<int,int>> count;
        
        for(int i=0;i<=n;i++)
        {
            int c=0;
            for(int j=0;j<=n;j++)
            {
                if(dp[j][i]==1)
                {
                    c++;
                }
            }
             if(c>0)
                    count.push_back(make_pair(c,i));
        }
        
        int num=-1;
        
        for(int i=0;i<count.size();i++)
        {
            if(count[i].first==n-1)
            {
                for(int j=0;j<=n;j++)
                {
                    if(dp[count[i].second][j]==1)
                        return num;
                }
                
                num=count[i].second;
            }
        }
        
            return num;
            
    }
};