class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int l=0,k=0,i;
        int counter=1;
        int m =n;
        while(k<n && l<m)
        {
            for(i=l;i<m;i++)
            {
                ans[k][i]=counter;
                counter++;
            }
            k++;
           
            for(int i=k;i<n;i++)
            {
                ans[i][m-1]=counter;
                counter++;
            }
            m--;
         
            if(k<n)
            {
                for(i=m-1;i>=l;i--)
                {
                    ans[n-1][i]=counter;
                    counter++;
                }
                n--;
            }
            
            if(l<m)
            {
                for(i=n-1;i>=k;i--)
                {
                    ans[i][l]=counter;
                    counter++;
                }
                l++;
               
            }
                 
        }
        
        return ans;
    }
};