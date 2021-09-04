class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> mr(n,INT_MIN),mc(m,INT_MIN);
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                mr[i]=max(mr[i],grid[i][j]),mc[j]=max(mc[j],grid[i][j]);
        
        int ans=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                ans+=min(mr[i],mc[j])-grid[i][j];
        
        return ans;
    }
};
