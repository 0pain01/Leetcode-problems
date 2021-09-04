class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        vector<vector<int>> arr;
        arr=grid;
            
        int n= grid.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int max1=0,max2=0;
                
                for(int k=0;k<n;k++){
                    if(max1<grid[i][k])
                        max1=grid[i][k];
                }
                
                for(int k=0;k<n;k++){
                    if(max2<grid[k][j])
                        max2=grid[k][j];
                }
                
                grid[i][j]=min(max1,max2);
            }
        }
        
        int sum=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=grid[i][j]-arr[i][j];
            }
        
        }
        
        return sum;
    }
};