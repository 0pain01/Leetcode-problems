class Solution {
public:
    bool b_search(int i,int j,vector<vector<int>> matrix, int target)
    {
        int l=0,r=j;
        int mid;
        while(l<=r)
        {
            mid =l+(r-l)/2;
            if(matrix[i][mid]==target)
                return true;
            
            else if(matrix[i][mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool it=false;
        
        for(int i=0;i<m;i++)
        {
            if(matrix[i][n-1]>=target)
            {
                return b_search(i,n-1,matrix,target);
            }

        }
        
        return false;
    }
};