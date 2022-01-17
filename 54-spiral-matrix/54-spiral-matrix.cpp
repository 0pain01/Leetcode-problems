class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m =matrix[0].size();
        int l=0,k=0,i;
        vector<int> res;
        
        while(k<n && l<m)
        {
            for(i=l;i<m;i++)
            {
                res.push_back(matrix[k][i]);
            }
           
            k++;
           
            
            for(int i=k;i<n;i++)
            {
                res.push_back(matrix[i][m-1]);
            }
           m--;
         
            
            if(k<n)
            {
                for(i=m-1;i>=l;i--)
                {
                    res.push_back(matrix[n-1][i]);
                }
                n--;
            }
            
           
            if(l<m)
            {
                for(i=n-1;i>=k;i--)
                {
                    res.push_back(matrix[i][l]);
                }
                l++;
               
            }
            
              
              
        }
        
        return res;
    }
};